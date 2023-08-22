// direttive d'inclusione
#include "ListItem.h"
#include "ItemRenderer.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>
#include <QPushButton>
#include <iostream>


ListItem::~ListItem()
{
    delete widget;
}

ListItem::ListItem(AbstractProduct* product, QWidget* parent) : QWidget(parent), product(product) {
    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    // setup immagine
    QPixmap image_object(":/assets/images/placeholder.svg");
    QLabel* image = new QLabel();
    image->setPixmap(image_object.scaled(96, 96, Qt::AspectRatioMode::KeepAspectRatio));


    // setup custom layout
    ItemRenderer* renderer = new ItemRenderer;
    product->accept(*renderer);
    QVBoxLayout* renderedLayout = renderer->getRenderedLayout();

    // setup dei bottoni
    QHBoxLayout* actions = new QHBoxLayout();
    deleteButton = new QPushButton(QIcon(QPixmap(":/assets/icons/delete.svg")), "");
    editButton   = new QPushButton(QIcon(QPixmap(":/assets/icons/edit.svg")), "");
    actions->addWidget(deleteButton);
    actions->addWidget(editButton);
    actions->setAlignment(Qt::AlignRight| Qt::AlignTop);

    actions->addStretch();

    connect(deleteButton, SIGNAL(clicked()), this, SLOT(emitDeleteSignal()));
    connect(editButton, SIGNAL(clicked()), this, SLOT(emitUpdateSignal()));

    // aggiunta dei bottoni al layout.
    layout->addWidget(image);
    layout->addLayout(renderedLayout);
    layout->addLayout(actions);

    // setting allineamenti dei widget
    layout->setAlignment(image, Qt::AlignLeft | Qt::AlignTop);
    layout->setAlignment(widget, Qt::AlignCenter| Qt::AlignTop);

}

QWidget *ListItem::getWidget() const {
    return widget;
}

QPushButton *ListItem::getEditButton() const {
    return editButton;
}

QPushButton *ListItem::getDeleteButton() const {
    return deleteButton;
}

void ListItem::emitDeleteSignal() {
    std::cout << "delete product with nome: " << product->getNome() <<  std::endl;
    emit deletedProduct(product);
}

void ListItem::emitUpdateSignal()
{
    std::cout << "update product with nome: " << product->getNome() <<  std::endl;
    emit updatedProduct(product);
}


