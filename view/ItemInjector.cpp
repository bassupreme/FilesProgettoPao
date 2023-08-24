#include "ItemInjector.h"
#include "model/Virtuale.h"
#include "model/Fisico.h"
#include "model/Noleggio.h"



ItemInjector::ItemInjector(EditorFisico *editorFisico) : editorFisico(editorFisico){

}

ItemInjector::ItemInjector(EditorVirtuale *editorVirtuale) : editorVirtuale(editorVirtuale) {

}

ItemInjector::ItemInjector(EditorNoleggio *editorNoleggio) : editorNoleggio(editorNoleggio){

}

void ItemInjector::visit(const Virtuale& product) {
    editorVirtuale->injectItem(product);
}

void ItemInjector::visit(const Fisico& product) {
    editorFisico->injectItem(product);
}

void ItemInjector::visit(const Noleggio& product) {
    editorNoleggio->injectItem(product);
}

