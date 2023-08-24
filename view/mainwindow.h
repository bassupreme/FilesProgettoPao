#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <string>
#include <QToolBar>
#include <QMainWindow>
#include <QWidget>
#include <QStackedWidget>

class MainWindow;

#include "ResultsWidget.h"
#include "FilterWidget.h"
#include "model/AbstractProduct.h"
#include "service/Filter.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    std::vector<AbstractProduct*> aux;
    ResultsWidget* resultsWidget;
    FilterWidget* filterWidget;
    QStackedWidget* stackedWidget;
    QToolBar* toolbar;
    void showStatus(const std::string& message, const unsigned int duration = 0);
    void clearStack();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void clearResults();
public slots:
    std::vector<AbstractProduct*>& getMemory();
    void createDataset();
    void openDataset();
    void toggleToolbar();
    void createProduct();
    void deleteProduct(AbstractProduct*);
    void updateProduct(AbstractProduct*);
    void search(Filter*);
};
#endif // MAINWINDOW_H
