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
    void disable();
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
#endif
