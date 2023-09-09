#ifndef ITEMINJECTOR_H
#define ITEMINJECTOR_H

#include <vector>
#include <string>
#include "model/IConstVisitor.h"
#include "EditorFisico.h"
#include "EditorVirtuale.h"
#include "EditorNoleggio.h"


class ItemInjector : public IConstVisitor {
private:
    EditorFisico* editorFisico;
    EditorVirtuale* editorVirtuale;
    EditorNoleggio* editorNoleggio;
public:
    ItemInjector(EditorFisico* editorFisico = nullptr);
    ItemInjector(EditorVirtuale* editorVirtuale = nullptr);
    ItemInjector(EditorNoleggio* editorNoleggio = nullptr);
    virtual void visit(const Virtuale&);
    virtual void visit(const Fisico&);
    virtual void visit(const Noleggio&);
};

#endif
