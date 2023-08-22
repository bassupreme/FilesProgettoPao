#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <string>
#include <QToolBar>
#include <QMainWindow>
#include <QWidget>
#include <QStackedWidget>
#include "ResultsWidget.h"
#include "FilterWidget.h"
#include "TestProductEditor.h"
#include "model/AbstractProduct.h"
#include "service/Filter.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    ResultsWidget* resultsWidget;
    FilterWidget* filterWidget;
    QStackedWidget* stackedWidget;
    QToolBar* toolbar;
    TestProductEditor* productEditor;
    void showStatus(const std::string& message, const unsigned int duration = 0);
    void clearStack();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void toggleToolbar();
    void deleteProduct(AbstractProduct*);
    void updateProduct(AbstractProduct*);
    void search(Filter*);
};
#endif // MAINWINDOW_H
