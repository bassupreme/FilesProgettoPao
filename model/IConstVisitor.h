#ifndef ICONSTVISITOR_H
#define ICONSTVISITOR_H

class Virtuale;
class Fisico;
class Noleggio;

class IConstVisitor {
public:
    virtual ~IConstVisitor() {}
    virtual void visit(const Virtuale&) = 0;
    virtual void visit(const Fisico&) = 0;
    virtual void visit(const Noleggio&) = 0;
};


#endif
