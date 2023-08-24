#include "ItemCreator.h"
#include "EditorFisico.h"
#include "EditorVirtuale.h"
#include "EditorNoleggio.h"
#include <QComboBox>
#include <QVBoxLayout>

ItemCreator::ItemCreator(MainWindow* mainWindow, QWidget* parent) : QWidget(parent), mainWindow(mainWindow) {

    // layout
    QVBoxLayout* layout = new QVBoxLayout();

    // comboBox
    QComboBox* type_input = new QComboBox();
    layout->setAlignment(type_input, Qt::AlignHCenter | Qt::AlignTop);
    type_input->setObjectName("type-input");
    type_input->addItem("Fisico");
    type_input->addItem("Virtuale");
    type_input->addItem("Noleggio");
    layout->addWidget(type_input);

    // stackedEditor

    stackedEditors = new QStackedWidget();
    layout->setAlignment(stackedEditors, Qt::AlignHCenter | Qt::AlignTop);

    EditorFisico* editorFisico = new EditorFisico(mainWindow);
    stackedEditors->addWidget(editorFisico);
    editors.push_back(editorFisico);

    EditorVirtuale* editorVirtuale = new EditorVirtuale(mainWindow);
    stackedEditors->addWidget(editorVirtuale);
    editors.push_back(editorVirtuale);

    EditorNoleggio* editorNoleggio = new EditorNoleggio(mainWindow);
    stackedEditors->addWidget(editorNoleggio);
    editors.push_back(editorNoleggio);

    layout->addWidget(stackedEditors);
    setLayout(layout);

    connect(type_input, qOverload<int>(&QComboBox::currentIndexChanged), this, &ItemCreator::showType);
}

void ItemCreator::create() {
    // logica per creare il tutto
}

void ItemCreator::showType(int index) {
    stackedEditors->setCurrentIndex(index);
}
