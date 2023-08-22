#ifndef RESULTSWIDGET_H
#define RESULTSWIDGET_H

// direttive d'inclusione
#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QMainWindow>
#include <vector>
#include "ListItem.h"
#include "model/AbstractProduct.h"

class ResultsWidget : public QWidget {
    Q_OBJECT
private:
    QGridLayout* verticalLayout;
    std::vector<ListItem*> listItems;
    QMainWindow* mainWindow;
public:
    ~ResultsWidget();
    ResultsWidget(QMainWindow* mainWindow, QWidget* parent = nullptr);
    void renderResults(std::vector<AbstractProduct*>&);
};

#endif // RESULTSWIDGET_H
