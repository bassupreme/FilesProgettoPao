#include "ItemEditorRenderer.h"
#include "model/Fisico.h"
#include "model/Virtuale.h"
#include "model/Noleggio.h"
#include "TestProductEditor.h"
#include "EditorFisico.h"
#include "EditorVirtuale.h"
#include "EditorNoleggio.h"
#include "ItemInjector.h"

ItemEditorRenderer::ItemEditorRenderer(MainWindow *mainWindow) : mainWindow(mainWindow) {}

void ItemEditorRenderer::visit(Virtuale& prodotto) {
    renderedEditor = new EditorVirtuale(mainWindow, &prodotto);
}

void ItemEditorRenderer::visit(Fisico& prodotto) {
    EditorFisico* editor= new EditorFisico(mainWindow, &prodotto);
    ItemInjector* injector = new ItemInjector(editor);
    prodotto.accept(*injector);
    renderedEditor = editor;
}

void ItemEditorRenderer::visit(Noleggio& prodotto) {
    renderedEditor = new EditorNoleggio(mainWindow, &prodotto);
}

QWidget *ItemEditorRenderer::getRenderedEditor() const {
    return renderedEditor;
}
