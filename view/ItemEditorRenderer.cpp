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
    EditorVirtuale* editor = new EditorVirtuale(mainWindow, &prodotto);
    ItemInjector* injector = new ItemInjector(editor);
    prodotto.accept(*injector);
    renderedEditor = editor;
}

void ItemEditorRenderer::visit(Fisico& prodotto) {
    EditorFisico* editor= new EditorFisico(mainWindow, &prodotto);
    ItemInjector* injector = new ItemInjector(editor);
    prodotto.accept(*injector);
    renderedEditor = editor;
}

void ItemEditorRenderer::visit(Noleggio& prodotto) {
    EditorNoleggio* editor = new EditorNoleggio(mainWindow, &prodotto);
    ItemInjector* injector = new ItemInjector(editor);
    prodotto.accept(*injector);
    renderedEditor = editor;
}

QWidget *ItemEditorRenderer::getRenderedEditor() const {
    return renderedEditor;
}
