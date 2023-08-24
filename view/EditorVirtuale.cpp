#include "EditorVirtuale.h"
#include <QVBoxLayout>
#include <QFormLayout>

EditorVirtuale::EditorVirtuale(MainWindow *mainWindow, AbstractProduct *subject, QWidget *parent) : AbstractEditor(mainWindow, subject, parent) {
        // setup oggetti grafici di questo editor specifico
    editorVirtuale = new QLabel("EDITOR VIRTUALE");

    // set up layout verticale
    QVBoxLayout* vbox = new QVBoxLayout(this);
    vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    // setup form layout
    QFormLayout* form = new QFormLayout();
    form->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);
    vbox->addLayout(form);


    form->addRow("id:", getBoxId());
    form->addRow("prezzo:", getBoxPrezzo());
    form->addRow("nome:", getBoxNome());
    form->addRow("imagePath:", getBoxImagePath());
    form->addRow("quale editor:", editorVirtuale); // questo viene poi sostituito dagli oggetti specifici di ogni editor
    form->addRow("apply changes:", getButtonApply());
}

void EditorVirtuale::update()
{

}

void EditorVirtuale::create()
{

}

void EditorVirtuale::injectItem(const Virtuale& product) {


}
