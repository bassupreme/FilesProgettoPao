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
    EditorFisico(MainWindow* mainWindow, AbstractProduct* subject = nullptr, QWidget* parent = nullptr);
    virtual AbstractProduct* update(); // modifica del prodotto
    virtual AbstractProduct* create(); // creazione del prodotto
    void injectItem(const Fisico&);
private slots:
    void emitSignalUpdate();
    void emitSignalCreate();
public slots:
    void updatedProduct(AbstractProduct*);
    void CreatedProduct(AbstractProduct*);
signals:
    void signalUpdated(AbstractProduct*);
    void signalCreated(AbstractProduct*);
};

#endif // EDITORFISICO_H
