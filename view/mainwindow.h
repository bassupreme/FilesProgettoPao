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
#include "service/Memory.h"
// inclusioni persistenza dei dati
#include "filePersistence/JsonFile.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    bool hasUnsavedChanges;
    Buffer* buffer;
    Memory& memory;
    JsonFile* jsonFile;
    // std::vector<AbstractProduct*> aux;
    ResultsWidget* resultsWidget;
    FilterWidget* filterWidget;
    QStackedWidget* stackedWidget;
    QToolBar* toolbar;
    QAction* createItem;
    void clearStack();
public:
    MainWindow(Memory& memory, QWidget *parent = nullptr);
    ~MainWindow();
    void clearResults();
    void showStatus(const std::string& message, const unsigned int duration = 0);
    void setHasUnsavedChanges(const bool&);
    Buffer *getBuffer() const;
    Memory& getMemory() const;
public slots:
    // std::vector<AbstractProduct*>& getMemory();
    void createDataset();
    void openDataset();
    void writeDataset();
    void toggleToolbar();
    void createProduct();
    void deleteProduct(const AbstractProduct*);
    void updateProduct(const AbstractProduct*);
    void search(Filter*);
};
#endif // MAINWINDOW_H
