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
    virtual AbstractProduct* update() const; // modifica del prodotto
    virtual AbstractProduct* create() const; // creazione del prodotto
    QCheckBox *getCheckBoxUsato() const;
    void injectItem(const Fisico&);
signals:
    void signalUpdated(const AbstractProduct*);
private slots:
    void emitSignalUpdate();

};
#endif
