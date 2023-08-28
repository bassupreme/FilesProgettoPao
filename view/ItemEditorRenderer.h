#ifndef ITEMEDITORRENDERER_H
#define ITEMEDITORRENDERER_H

#include "model/IVisitor.h"
#include "AbstractEditor.h"
#include "mainwindow.h"
#include <QWidget>

class ItemEditorRenderer : public IConstVisitor {
private:
    MainWindow* mainWindow;
    AbstractEditor* renderedEditor;
public:
    ItemEditorRenderer(MainWindow* mainWindow);
    virtual void visit(const Virtuale&);
    virtual void visit(const Fisico&);
    virtual void visit(const Noleggio&);
    QWidget* getRenderedEditor() const;
};

#endif // ITEMEDITORRENDERER_H
