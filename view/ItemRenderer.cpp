#include "ItemRenderer.h"
#include "model/Fisico.h"
#include "model/Virtuale.h"
#include "model/Noleggio.h"
#include <QVBoxLayout>
#include <QLabel>

void ItemRenderer::visit(const Fisico& product) {
    renderedLayout = new QVBoxLayout();
    renderedLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QLabel* nome = new QLabel(QString::fromStdString(product.getNome()));
    QLabel* usato;
    if (product.getUsato()) usato = new QLabel(QString::fromStdString("usato"));
    else usato = new QLabel(QString::fromStdString("nuovo"));

    renderedLayout->addWidget(nome);
    renderedLayout->addWidget(usato);

    // settare allineamneto all'interno del layout
    renderedLayout->setAlignment(nome, Qt::AlignCenter | Qt::AlignTop);
    renderedLayout->setAlignment(usato, Qt::AlignCenter | Qt::AlignTop);
}

void ItemRenderer::visit(const Noleggio& product) {
    renderedLayout = new QVBoxLayout();
    renderedLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QLabel* nome = new QLabel(QString::fromStdString(product.getNome()));
    QLabel* usato;
    if (product.getUsato()) usato = new QLabel(QString::fromStdString("usato"));
    else usato = new QLabel(QString::fromStdString("nuovo"));

    renderedLayout->addWidget(nome);
    renderedLayout->addWidget(usato);

    // settare allineamento all'interno del layout
    renderedLayout->setAlignment(nome, Qt::AlignCenter | Qt::AlignTop);
    renderedLayout->setAlignment(usato, Qt::AlignCenter | Qt::AlignTop);
}

void ItemRenderer::visit(const Virtuale& product) {
    renderedLayout = new QVBoxLayout();

    QLabel* nome = new QLabel(QString::fromStdString(product.getNome()));
    renderedLayout->addWidget(nome);
}

QVBoxLayout* ItemRenderer::getRenderedLayout() const {
    return renderedLayout;
}
