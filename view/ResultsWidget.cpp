#include "ResultsWidget.h"
#include "model/AbstractProduct.h"
#include "model/Fisico.h"
#include "model/Virtuale.h"
#include "model/Noleggio.h"
#include "mainwindow.h"
#include <string>
#include <QScrollArea>


void ResultsWidget::destroyListItems() {
    if (!listItems.empty()) {
        std::vector<ListItem*>::const_iterator cit = listItems.begin();
        for(; cit != listItems.end(); cit++) {
            delete *cit;
        }
        listItems.clear();
    }
}

ResultsWidget::~ResultsWidget() {
    destroyListItems();
}

ResultsWidget::ResultsWidget(QMainWindow* mainWindow, QWidget* parent) : QWidget(parent), mainWindow(mainWindow) {
    // creazione del layout
    verticalLayout = new QVBoxLayout();
    verticalLayout->setAlignment(Qt::AlignRight | Qt::AlignTop);
    setLayout(verticalLayout);
}

void ResultsWidget::renderResults(const std::vector<AbstractProduct*>& results) {

    for(std::vector<AbstractProduct*>::const_iterator cit = results.begin(); cit != results.end(); cit++) {

        // creazione widget
        ListItem* listItem = new ListItem(*cit, this);

        connect(listItem, SIGNAL(deletedProduct(AbstractProduct*)), mainWindow, SLOT(deleteProduct(AbstractProduct*)));
        connect(listItem, SIGNAL(updatedProduct(AbstractProduct*)), mainWindow, SLOT(updateProduct(AbstractProduct*)));

        // personalizzazione widget
        // QSizePolicy widgetPolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        // widgetPolicy.setVerticalStretch(0);
        // listItem->setSizePolicy(widgetPolicy);

        // aggiunta al layout
        listItems.push_back(listItem);
        verticalLayout->setAlignment(listItem, Qt::AlignRight | Qt::AlignTop);
        verticalLayout->addWidget(listItem);
    }
}

void ResultsWidget::deleteResult(const AbstractProduct* product) {
    if (!listItems.empty()) {
        std::vector<ListItem*>::const_iterator cit = listItems.begin();
        while((*cit)->getProduct() != product) {
            cit++;
        }
        delete *cit;
        listItems.erase(cit);
    }
}

void ResultsWidget::clearResults() {
    destroyListItems();
}

