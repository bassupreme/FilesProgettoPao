#ifndef ITEMEDITORRENDERER_H
#define ITEMEDITORRENDERER_H

#include "model/IVisitor.h"
#include "mainwindow.h"
#include <QWidget>

class ItemEditorRenderer : public IVisitor {
private:
    MainWindow* mainWindow;
    QWidget* renderedEditor;
public:
    ItemEditorRenderer(MainWindow* mainWindow);
    virtual void visit(Virtuale&);
    virtual void visit(Fisico&);
    virtual void visit(Noleggio&);
    QWidget* getRenderedEditor() const;
};

#endif // ITEMEDITORRENDERER_H
