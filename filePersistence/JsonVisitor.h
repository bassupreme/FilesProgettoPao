#ifndef JSONVISITOR_H
#define JSONVISITOR_H

// direttive di inclusione
#include "model/IConstVisitor.h"
#include <QJsonObject>

class JsonVisitor: public IConstVisitor {
private:
    QJsonObject jsonObject;
public:
    virtual void visit(const Virtuale&);
    virtual void visit(const Fisico&);
    virtual void visit(const Noleggio&);
    QJsonObject getJsonObject();
};

#endif
