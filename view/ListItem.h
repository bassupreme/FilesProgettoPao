#ifndef LISTITEM_H
#define LISTITEM_H

#include <QPushButton>
#include <QVBoxLayout>
#include "model/AbstractProduct.h"

class ListItem : public QWidget {
    Q_OBJECT
private:
    const AbstractProduct* product;
    QPushButton* editButton;
    QPushButton* deleteButton;
    QVBoxLayout* infoLayout;
public:
    virtual ~ListItem();
    ListItem(const AbstractProduct* product, QWidget* parent = nullptr);
    const AbstractProduct* getProduct() const;
    QPushButton* getEditButton() const;
    QPushButton* getDeleteButton() const;
private slots:
    void emitDeleteSignal();
    void emitUpdateSignal();

signals:
    void deletedProduct(const AbstractProduct* product);
    void updatedProduct(const AbstractProduct* product);
};

#endif
