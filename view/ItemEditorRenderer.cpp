#include "ItemEditorRenderer.h"
#include "model/Fisico.h"
#include "model/Virtuale.h"
#include "model/Noleggio.h"
#include "TestProductEditor.h"
#include "EditorFisico.h"
#include "EditorVirtuale.h"
#include "EditorNoleggio.h"


ItemEditorRenderer::ItemEditorRenderer(MainWindow *mainWindow) : mainWindow(mainWindow) {}

void ItemEditorRenderer::visit(Virtuale& prodotto) {
    renderedEditor = new EditorVirtuale(mainWindow, &prodotto);
}

void ItemEditorRenderer::visit(Fisico& prodotto) {

    // usare questo visitor per settare un ulteriore layout in modo da
    // non dover ricorrere al dynamic cast all'interno di ogni singolo editor.
    renderedEditor = new EditorFisico(mainWindow, &prodotto);
}

void ItemEditorRenderer::visit(Noleggio& prodotto) {
    renderedEditor = new EditorNoleggio(mainWindow, &prodotto);
}

QWidget *ItemEditorRenderer::getRenderedEditor() const {
    return renderedEditor;
}
