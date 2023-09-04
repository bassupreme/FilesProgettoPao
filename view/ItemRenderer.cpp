#include "ItemRenderer.h"
#include "model/Fisico.h"
#include "model/Virtuale.h"
#include "model/Noleggio.h"
#include <QVBoxLayout>
#include <QLabel>

void ItemRenderer::visit(const Fisico& product) {
    renderedLayout = new QVBoxLayout();
    renderedLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QLabel* nome = new QLabel(QString::fromStdString("nome: " + product.getNome()));
    QLabel* usato;
    if (product.getUsato()) usato = new QLabel(QString::fromStdString("condizione: usato"));
    else usato = new QLabel(QString::fromStdString("condizione: nuovo"));
    QLabel* prezzo = new QLabel(QString::fromStdString("prezzo: " + std::to_string(product.getPrezzo())));

    renderedLayout->addWidget(nome);
    renderedLayout->addWidget(usato);
    renderedLayout->addWidget(prezzo);

    // settare allineamneto all'interno del layout
    renderedLayout->setAlignment(nome, Qt::AlignLeft| Qt::AlignTop);
    renderedLayout->setAlignment(usato, Qt::AlignLeft | Qt::AlignTop);
    renderedLayout->setAlignment(prezzo, Qt::AlignLeft | Qt::AlignTop);
}

void ItemRenderer::visit(const Noleggio& product) {
    renderedLayout = new QVBoxLayout();
    renderedLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QLabel* nome = new QLabel(QString::fromStdString(product.getNome()));
    QLabel* usato;
    if (product.getUsato()) usato = new QLabel(QString::fromStdString("condizione: usato"));
    else usato = new QLabel(QString::fromStdString("condizione: nuovo"));
    QLabel* prezzo = new QLabel(QString::fromStdString("prezzo orario: " + std::to_string(product.getPrezzo())));
    QLabel* labelNoleggiatore = new QLabel(QString::fromStdString("noleggiatore: " + product.getNoleggiatore()));
    QLabel* labelNoleggiante = new QLabel(QString::fromStdString("noleggiante: " + product.getNoleggiante()));

    renderedLayout->addWidget(nome);
    renderedLayout->addWidget(usato);
    renderedLayout->addWidget(prezzo);
    renderedLayout->addWidget(labelNoleggiante);
    renderedLayout->addWidget(labelNoleggiatore);

    // settare allineamento all'interno del layout
    renderedLayout->setAlignment(nome, Qt::AlignLeft | Qt::AlignTop);
    renderedLayout->setAlignment(usato, Qt::AlignLeft | Qt::AlignTop);
    renderedLayout->setAlignment(prezzo, Qt::AlignLeft | Qt::AlignTop);
    renderedLayout->setAlignment(labelNoleggiatore, Qt::AlignLeft | Qt::AlignTop);
    renderedLayout->setAlignment(labelNoleggiante, Qt::AlignLeft | Qt::AlignTop);
}

void ItemRenderer::visit(const Virtuale& product) {
    renderedLayout = new QVBoxLayout();
    renderedLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QLabel* nome = new QLabel(QString::fromStdString("nome: " + product.getNome()));
    QLabel* prezzo = new QLabel(QString::fromStdString("prezzo orario: " + std::to_string(product.getPrezzo())));
    QLabel* virtualInfo = new QLabel(QString::fromStdString("disponibile per il download"));

    renderedLayout->addWidget(nome);
    renderedLayout->addWidget(prezzo);
    renderedLayout->addWidget(virtualInfo);

    renderedLayout->setAlignment(nome, Qt::AlignLeft | Qt::AlignTop);
    renderedLayout->setAlignment(prezzo, Qt::AlignLeft | Qt::AlignTop);
    renderedLayout->setAlignment(virtualInfo, Qt::AlignLeft | Qt::AlignTop);

}

QVBoxLayout* ItemRenderer::getRenderedLayout() const {
    return renderedLayout;
}
