#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "ResultsWidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    ResultsWidget* resultsWidget;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

};
#endif // MAINWINDOW_H
