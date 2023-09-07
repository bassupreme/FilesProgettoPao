#ifndef ABSTRACTEDITOR_H
#define ABSTRACTEDITOR_H

// direttive d'inclusione
#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QTextEdit>
#include <QFormLayout>
#include <model/AbstractProduct.h>

// inclusioni di test
#include "mainwindow.h"


class AbstractEditor : public QWidget {
    Q_OBJECT
private:
    QFormLayout* container;
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
    QFormLayout* getContainer() const;
    QSpinBox* getBoxId() const;
    QDoubleSpinBox* getBoxPrezzo() const;
    QLineEdit* getBoxNome() const;
    QLineEdit* getBoxImagePath() const;
    QTextEdit* getBoxDescription() const;
    QPushButton* getButtonApply() const;
    const AbstractProduct* getSubject() const;
    MainWindow* getMainWindow() const;
    virtual AbstractProduct* update() const = 0; // modifica del prodotto
    virtual AbstractProduct* create() const = 0; // creazione del prodotto
private slots:
    void selectImage();
protected slots:
    void updatedProduct(const AbstractProduct*);
};
#endif // ABSTRACTEDITOR_H
