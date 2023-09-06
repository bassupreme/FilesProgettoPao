#ifndef EDITORFISICO_H
#define EDITORFISICO_H

// direttive d'inclusione
#include <QCheckBox>
#include "AbstractEditor.h"
#include "model/AbstractProduct.h"
#include "mainwindow.h"

class EditorFisico : public AbstractEditor {
    Q_OBJECT
private:
    QCheckBox* checkBoxUsato;
public:
    EditorFisico(MainWindow* mainWindow, const AbstractProduct* subject = nullptr, QWidget* parent = nullptr);
    virtual AbstractProduct* update(); // modifica del prodotto
    virtual AbstractProduct* create(); // creazione del prodotto
    QCheckBox *getCheckBoxUsato() const;
    void injectItem(const Fisico&);
signals:
    void signalUpdated(const AbstractProduct*);
private slots:
    void emitSignalUpdate();
    // virtual void updatedProduct(const AbstractProduct*);

};

#endif // EDITORFISICO_H
