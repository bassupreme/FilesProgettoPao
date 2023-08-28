#ifndef RESULTSWIDGET_H
#define RESULTSWIDGET_H

// direttive d'inclusione
#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
// #include <QGridLayout>
#include <QPushButton>
#include <QMainWindow>
#include <vector>
#include "ListItem.h"
#include "model/AbstractProduct.h"


class ResultsWidget : public QWidget {
    Q_OBJECT
private:
    QVBoxLayout* verticalLayout;
    std::vector<ListItem*> listItems;
    QMainWindow* mainWindow;
    void destroyListItems();
public:
    ~ResultsWidget();
    ResultsWidget(QMainWindow* mainWindow, QWidget* parent = nullptr);
    void renderResults(const std::vector<const AbstractProduct*>&);
    void deleteResult(const AbstractProduct*);
    void clearResults();

};

#endif // RESULTSWIDGET_H
