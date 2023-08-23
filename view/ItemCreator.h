#ifndef ITEMCREATOR_H
#define ITEMCREATOR_H

// direttive d'inclusione
#include <QSpinBox>
#include <QStackedWidget>

class ItemCreator {
private:
    QSpinBox* selectType;
    QStackedWidget* currentEditor;
};

#endif // ITEMCREATOR_H
