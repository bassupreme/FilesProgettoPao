#include "FilterWidget.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QFormLayout>
#include "service/SubstringMatcher.h"
#include "service/PriceMatcher.h"

void FilterWidget::clearCurrentFilter() {
    delete currentFilter;
    currentFilter = nullptr;
}

void FilterWidget::filterInitialSetup() {
    searchBar->setEnabled(false);
    searchBar->setText("");
    lowerBox->setEnabled(false);
    lowerBox->setValue(0.0);
    lowerBox->setMinimum(0.0);
    upperBox->setEnabled(false);
    upperBox->setValue(0.0);
    upperBox->setMinimum(0.0);
    clearFilter->setEnabled(false);
    priceEnabled->setChecked(false);
    searchEnabled->setChecked(false);
}

FilterWidget::~FilterWidget() {
    delete currentFilter;
}

FilterWidget::FilterWidget(QWidget* parent) : QWidget(parent), currentFilter(nullptr) {
    // set up layout verticale
    QVBoxLayout* vbox = new QVBoxLayout(this);
    vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    // setup form layout
    QFormLayout* form = new QFormLayout();
    form->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);
    vbox->addLayout(form);

    // setup widget
    QHBoxLayout* searchLayout = new QHBoxLayout();
    searchEnabled = new QCheckBox();
    searchBar = new QLineEdit();
    searchLayout->addWidget(searchEnabled);
    searchLayout->addWidget(searchBar);

    QHBoxLayout* priceLayout = new QHBoxLayout();
    priceEnabled = new QCheckBox();
    lowerBox = new QDoubleSpinBox();
    upperBox = new QDoubleSpinBox();
    priceLayout->addWidget(priceEnabled);
    priceLayout->addWidget(lowerBox);
    priceLayout->addWidget(upperBox);
    clearFilter = new QPushButton("CLEAR");
    applyFilter = new QPushButton("APPLY");

    form->addRow("search:", searchLayout);
    form->addRow("price limit:", priceLayout);
    form->addRow("clear:", clearFilter);
    form->addRow("apply:", applyFilter);

    // setup iniziale del widget
    filterInitialSetup();

    // connect segnali e slot
    connect(applyFilter, SIGNAL(clicked()), this, SLOT(emitSignalFilter()));
    connect(clearFilter, SIGNAL(clicked(bool)), this, SLOT(clearFilterWidget()));
    connect(searchEnabled, SIGNAL(toggled(bool)), this, SLOT(enableSearchInput()));
    connect(priceEnabled, SIGNAL(toggled(bool)), this, SLOT(enablePriceInput()));
}

void FilterWidget::emitSignalFilter() {
    // creazione filter

    std::cout << "FilterWidget::emitSignalFilter" << std::endl;

    if (currentFilter != nullptr) {
        clearCurrentFilter();
    }
    currentFilter = new Filter();
    if (searchEnabled->isChecked()) {
        SubstringMatcher* ssMatcer = new SubstringMatcher(searchBar->text().toStdString());
        currentFilter->addMatcher(ssMatcer);
    }
    if (priceEnabled->isChecked()) {
        PriceMatcher* pMatcher = new PriceMatcher(lowerBox->value(), upperBox->value());
        currentFilter->addMatcher(pMatcher);
    }
    clearFilter->setEnabled(true);
    emit signalFilter(currentFilter);
}

void FilterWidget::enableSearchInput() {
    searchBar->setEnabled(searchEnabled->isChecked());
}

void FilterWidget::enablePriceInput() {
    lowerBox->setEnabled(priceEnabled->isChecked());
    upperBox->setEnabled(priceEnabled->isChecked());
}

void FilterWidget::clearFilterWidget() {
    clearCurrentFilter();
    filterInitialSetup();
    emit signalCleared(nullptr);
}


