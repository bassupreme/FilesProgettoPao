#ifndef LISTITEM_H
#define LISTITEM_H

// direttive d'inclusione
#include <QPushButton>
#include <QVBoxLayout>
#include "model/AbstractProduct.h"

class ListItem : public QWidget {
    Q_OBJECT
private:
    // QWidget* widget; // rendered widget
    AbstractProduct* product; // puntatore al prodotto da rappresentare
    QPushButton* editButton;
    QPushButton* deleteButton;
    QVBoxLayout* infoLayout;
    unsigned int idListItem; // non so se usarlo o meno.
public:
    virtual ~ListItem();
    ListItem(AbstractProduct* product, QWidget* parent = nullptr);
    const AbstractProduct* getProduct() const;
    // QWidget* getWidget() const;
    QPushButton* getEditButton() const;
    QPushButton* getDeleteButton() const;
private slots:
    void emitDeleteSignal();
    void emitUpdateSignal();

signals:
    void deletedProduct(AbstractProduct* product);
    void updatedProduct(AbstractProduct* product);
};

#endif // LISTITEM_H
