#ifndef ITEMRENDERER_H
#define ITEMRENDERER_H


#include <QWidget>
#include <QVBoxLayout>
#include "model/IConstVisitor.h"

class ItemRenderer : public IConstVisitor {
private:
    QVBoxLayout* renderedLayout;
public:
    virtual void visit(const Fisico&);
    virtual void visit(const Noleggio&);
    virtual void visit(const Virtuale&);
    QVBoxLayout* getRenderedLayout() const;
};

#endif
