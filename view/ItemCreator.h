#ifndef ITEMCREATOR_H
#define ITEMCREATOR_H

// direttive d'inclusione
#include <vector>
#include <QSpinBox>
#include <QStackedWidget>
#include <QWidget>
#include "mainwindow.h"
#include "AbstractEditor.h"
#include "model/AbstractProduct.h"

class ItemCreator : public QWidget {
    Q_OBJECT
private:
    QSpinBox* selectType;
    QStackedWidget* stackedEditors;
    std::vector<AbstractEditor*> editors;
    MainWindow* mainWindow;
public:
    ItemCreator(MainWindow* mainWindow, QWidget* parent = nullptr);
public slots:
    void create();
    void showType(int index);
};

#endif // ITEMCREATOR_H
