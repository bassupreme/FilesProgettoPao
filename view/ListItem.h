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
    const AbstractProduct* product; // puntatore al prodotto da rappresentare
    QPushButton* editButton;
    QPushButton* deleteButton;
    QVBoxLayout* infoLayout;
    unsigned int idListItem; // non so se usarlo o meno.
public:
    virtual ~ListItem();
    ListItem(const AbstractProduct* product, QWidget* parent = nullptr);
    const AbstractProduct* getProduct() const;
    // QWidget* getWidget() const;
    QPushButton* getEditButton() const;
    QPushButton* getDeleteButton() const;
private slots:
    void emitDeleteSignal();
    void emitUpdateSignal();

signals:
    void deletedProduct(const AbstractProduct* product);
    void updatedProduct(const AbstractProduct* product);
};

#endif // LISTITEM_H
