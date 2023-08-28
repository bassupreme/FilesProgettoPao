#ifndef ABSTRACTEDITOR_H
#define ABSTRACTEDITOR_H

// direttive d'inclusione
#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QTextEdit>
#include <model/AbstractProduct.h>

// inclusioni di test
#include "mainwindow.h"


class AbstractEditor : public QWidget {
private:
    QSpinBox* boxId;
    QDoubleSpinBox* boxPrezzo;
    QLineEdit* boxNome;
    QLineEdit* boxImagePath;
    QTextEdit* boxDescription;
    MainWindow* mainWindow;
    const AbstractProduct* subject;
    QPushButton* buttonApply;
public:
    virtual ~AbstractEditor();
    AbstractEditor(MainWindow* mainWindow, const AbstractProduct* subject = nullptr, QWidget* parent = nullptr);
    QSpinBox* getBoxId() const;
    QDoubleSpinBox* getBoxPrezzo() const;
    QLineEdit* getBoxNome() const;
    QLineEdit* getBoxImagePath() const;
    QTextEdit* getBoxDescription() const;
    QPushButton* getButtonApply() const;
    const AbstractProduct* getSubject() const;
    MainWindow* getMainWindow() const;
    virtual AbstractProduct* update() = 0; // modifica del prodotto
    virtual AbstractProduct* create() = 0; // creazione del prodotto
};

#endif // ABSTRACTEDITOR_H
