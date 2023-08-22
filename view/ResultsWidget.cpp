#include "ResultsWidget.h"
#include "../AbstractProduct.h"
#include "../Fisico.h"
#include "../Virtuale.h"
#include "../Noleggio.h"
#include <string>


ResultsWidget::~ResultsWidget()
{

}

ResultsWidget::ResultsWidget(QWidget* parent) : QWidget(parent){
    // creazione del layout
    verticalLayout = new QGridLayout(this);

    std::string array[] = { "porca: ", "elemento super fantastico numero: "};

    // creazione dei tanti bottoni che vanno a popolare il layout.
    for(int i = 0; i < 10; i++) {
        // creazione prodotto
        std::string nome = array[i%2] + std::to_string(i);

        AbstractProduct* product = new Fisico(i, 2.0, nome, "path", "descrizione", false);

        // creazione widget
        ListItem* listItem = new ListItem(product, this);

        // personalizzazione widget
        /*
        QSizePolicy widgetPolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        widgetPolicy.setVerticalStretch(0);
        listItem->setSizePolicy(widgetPolicy);

        */
        // aggiunta al layout
        verticalLayout->addWidget(listItem, i, 0);
        verticalLayout->setAlignment(listItem, Qt::AlignLeft| Qt::AlignTop);
        listItems.push_back(listItem);
    }
}
