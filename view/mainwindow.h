#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <string>
#include <QToolBar>
#include <QMainWindow>
#include <QWidget>
#include <QStackedWidget>
#include <QAction>
#include <map>

class MainWindow;

// inclusioni view
#include "ResultsWidget.h"
#include "FilterWidget.h"
// inlcudioni model
#include "model/AbstractProduct.h"
// inclusioni service
#include "service/Filter.h"
#include "service/Buffer.h"
// inclusioni persistenza dei dati
#include "filePersistence/JsonFile.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    bool hasUnsavedChanges;
    Buffer* buffer;
    JsonFile* jsonFile;
    // std::vector<AbstractProduct*> aux;
    ResultsWidget* resultsWidget;
    FilterWidget* filterWidget;
    QStackedWidget* stackedWidget;
    QToolBar* toolbar;
    QAction* createItem;
    void showStatus(const std::string& message, const unsigned int duration = 0);
    void clearStack();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void clearResults();
    void setHasUnsavedChanges(const bool&);
public slots:
    // std::vector<AbstractProduct*>& getMemory();
    Buffer *getBuffer();
    void createDataset();
    void openDataset();
    void toggleToolbar();
    void createProduct();
    void deleteProduct(AbstractProduct*);
    void updateProduct(AbstractProduct*);
    void search(Filter*);
};
#endif // MAINWINDOW_H
