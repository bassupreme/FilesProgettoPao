// direttive d'inclusione
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ResultsWidget.h"
#include <QVBoxLayout>
#include <QScrollArea>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {


    // creazione scrollArea
    QScrollArea* customScrollArea = new QScrollArea(this);
    // personalizzazione scrollarea
    customScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    customScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    customScrollArea->setWidgetResizable(true);

    // creazione widget risultati
    resultsWidget = new ResultsWidget(this);

    customScrollArea->setWidget(resultsWidget);

    setCentralWidget(customScrollArea);
}

MainWindow::~MainWindow() {

}

