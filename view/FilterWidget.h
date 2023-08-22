#ifndef FILTERWIDGET_H
#define FILTERWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QPushButton>
#include "service/Filter.h"

class FilterWidget : public QWidget {
    Q_OBJECT
private:
    bool hasControl;
    QLineEdit* searchBar;
    QSpinBox* lowerBox;
    QSpinBox* upperBox;
    QPushButton* clearFilter;
    QPushButton* applyFilter;
    Filter* currentFilter;
public:
    ~FilterWidget();
    FilterWidget(QWidget* parent = nullptr);
    /*
    QLineEdit *getsearchBar() const;
    QSpinBox* getLowerBox() const;
    QSpinBox* getUpperBox() const;
    QPushButton* getFilterButton() const;
    QPushButton* getClearFilterButton() const;
    const bool getHasControl() const;
    void setHasControl(const bool);
    Filter* getCurrentFilter() const;
    */
signals:
    void signalFilter(Filter*);
};

#endif // FILTERWIDGET_H
