#ifndef TESTPRODUCTEDITOR_H
#define TESTPRODUCTEDITOR_H

#include <QWidget>
#include <QPushButton>
#include <QMainWindow>
#include "service/Filter.h"
#include "model/AbstractProduct.h"

#include "mainwindow.h"

class TestProductEditor : public QWidget {
    Q_OBJECT
private:
    QMainWindow* mainWindow;
    AbstractProduct* subject;
    QPushButton* apply;
public:
    TestProductEditor(MainWindow* mainWindow, AbstractProduct* subject, QWidget* parent = nullptr);

private slots:
    void appliedChanges();
signals:
    void searchAll(Filter*);
};

#endif // TESTPRODUCTEDITOR_H
