#ifndef EDITORVIRTUALE_H
#define EDITORVIRTUALE_H

#include "AbstractEditor.h"
#include <QLabel>

class EditorVirtuale : public AbstractEditor {
private:
    QLabel* editorVirtuale;
public:
    EditorVirtuale(MainWindow* mainWindow, AbstractProduct* subject, QWidget* parent = nullptr);
    void injectItem(const Virtuale&);
    virtual void update();
    virtual void create();

};

#endif // EDITORVIRTUALE_H
