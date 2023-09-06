#ifndef FILTERWIDGET_H
#define FILTERWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QCheckBox>
#include "service/Filter.h"

class FilterWidget : public QWidget {
    Q_OBJECT
private:
    bool hasControl;
    QCheckBox* searchEnabled;
    QLineEdit* searchBar;
    QCheckBox* priceEnabled;
    QDoubleSpinBox* lowerBox;
    QDoubleSpinBox* upperBox;
    QPushButton* clearFilter;
    QPushButton* applyFilter;
    Filter* currentFilter;
    void clearCurrentFilter();
    void filterInitialSetup();
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

    QPushButton* getButtonApply() const;
private slots:
    void emitSignalFilter();
    void enableSearchInput();
    void enablePriceInput();
    void clearFilterWidget();
signals:
    void signalFilter(Filter*);
    void signalCleared(Filter*);
};

#endif // FILTERWIDGET_H
