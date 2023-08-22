#include "FilterWidget.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QFormLayout>

FilterWidget::~FilterWidget() {
    delete currentFilter;
}

FilterWidget::FilterWidget(QWidget* parent) : QWidget(parent) {
    // set up layout verticale
    QVBoxLayout* vbox = new QVBoxLayout(this);
    vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    // setup form layout
    QFormLayout* form = new QFormLayout();
    form->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);
    vbox->addLayout(form);

    // setup widget
    searchBar = new QLineEdit();
    lowerBox = new QSpinBox();
    upperBox = new QSpinBox();
    clearFilter = new QPushButton("CLEAR");
    applyFilter = new QPushButton("APPLY");

    form->addRow("search:", searchBar);
    form->addRow("lower price:", lowerBox);
    form->addRow("upper price:", upperBox);
    form->addRow("clear:", clearFilter);
    form->addRow("apply:", applyFilter);
}


