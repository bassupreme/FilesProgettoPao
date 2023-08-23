#ifndef EDITORNOLEGGIO_H
#define EDITORNOLEGGIO_H

#include "AbstractEditor.h"
#include <QLabel>
#include <QCheckBox>

class EditorNoleggio : public AbstractEditor {
private:
    QCheckBox* checkBoxUsato;
    QLineEdit* boxNoleggiante;
    QLineEdit* boxNoleggiatore;
public:
    EditorNoleggio(MainWindow* mainWindow, AbstractProduct* subject, QWidget* parent = nullptr);
    virtual void update();
    virtual void create();
};

#endif // EDITORNOLEGGIO_H
