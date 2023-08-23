#ifndef ABSTRACTEDITOR_H
#define ABSTRACTEDITOR_H

// direttive d'inclusione
#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <model/AbstractProduct.h>

// inclusioni di test
#include "mainwindow.h"


class AbstractEditor : public QWidget {
private:
    QSpinBox* boxId;
    QDoubleSpinBox* boxPrezzo;
    QLineEdit* boxNome;
    QLineEdit* boxImagePath;
    MainWindow* mainWindow;
    AbstractProduct* subject;
    QPushButton* buttonApply;
public:
    virtual ~AbstractEditor();
    AbstractEditor(MainWindow* mainWindow, AbstractProduct* subject, QWidget* parent = nullptr);
    QSpinBox* getBoxId() const;
    QDoubleSpinBox* getBoxPrezzo() const;
    QLineEdit* getBoxNome() const;
    QLineEdit* getBoxImagePath() const;
    QPushButton* getButtonApply() const;
    AbstractProduct* getSubject() const;
    MainWindow* getMainWindow() const;
    virtual void update() = 0; // modifica del prodotto
    virtual void create() = 0; // creazione del prodotto
};

#endif // ABSTRACTEDITOR_H
