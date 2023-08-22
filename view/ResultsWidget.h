#ifndef RESULTSWIDGET_H
#define RESULTSWIDGET_H

// direttive d'inclusione
#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <vector>
#include "../ListItem.h"

class ResultsWidget : public QWidget {
private:
    QGridLayout* verticalLayout;
    std::vector<ListItem*> listItems;
public:
    ~ResultsWidget();
    ResultsWidget(QWidget* parent = nullptr);
};

#endif // RESULTSWIDGET_H
