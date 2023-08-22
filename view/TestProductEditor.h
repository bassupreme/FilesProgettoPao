#ifndef TESTPRODUCTEDITOR_H
#define TESTPRODUCTEDITOR_H

#include <QWidget>
#include <QPushButton>
#include <QMainWindow>
#include "service/Filter.h"


class TestProductEditor : public QWidget {
    Q_OBJECT
private:
    QMainWindow* mainWindow;
    QPushButton* apply;
public:
    TestProductEditor(QMainWindow* mainWindow, QWidget* parent = nullptr);

private slots:
    void appliedChanges();
signals:
    void searchAll(Filter*);
};

#endif // TESTPRODUCTEDITOR_H
