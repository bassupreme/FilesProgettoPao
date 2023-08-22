#include "ResultsWidget.h"
#include "model/AbstractProduct.h"
#include "model/Fisico.h"
#include "model/Virtuale.h"
#include "model/Noleggio.h"
#include "mainwindow.h"
#include <string>
#include <QScrollArea>


ResultsWidget::~ResultsWidget() {
    for(std::vector<ListItem*>::const_iterator cit = listItems.begin(); cit != listItems.end(); cit++) {
        delete (*cit);
    }
}

ResultsWidget::ResultsWidget(QMainWindow* mainWindow, QWidget* parent) : QWidget(parent), mainWindow(mainWindow) {
    // creazione del layout
    verticalLayout = new QGridLayout();
    verticalLayout->setAlignment(Qt::AlignRight | Qt::AlignTop);
    setLayout(verticalLayout);
}

void ResultsWidget::renderResults(std::vector<AbstractProduct *>& results) {

    int i = 0;
    for(std::vector<AbstractProduct*>::const_iterator cit = results.begin(); cit != results.end(); cit++) {


        // creazione widget
        ListItem* listItem = new ListItem(*cit, this);

        connect(listItem, SIGNAL(deletedProduct(AbstractProduct*)), mainWindow, SLOT(deleteProduct(AbstractProduct*)));
        connect(listItem, SIGNAL(updatedProduct(AbstractProduct*)), mainWindow, SLOT(updateProduct(AbstractProduct*)));

        // personalizzazione widget
        QSizePolicy widgetPolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        widgetPolicy.setVerticalStretch(0);
        listItem->setSizePolicy(widgetPolicy);

        // aggiunta al layout
        listItems.push_back(listItem);
        verticalLayout->setAlignment(listItem, Qt::AlignRight | Qt::AlignTop);
        verticalLayout->addWidget(listItem, i, 0);
        i++;
    }
}

