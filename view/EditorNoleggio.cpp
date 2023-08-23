#include "EditorNoleggio.h"
#include "model/Noleggio.h"
#include <QVBoxLayout>
#include <QFormLayout>

EditorNoleggio::EditorNoleggio(MainWindow *mainWindow, AbstractProduct* subject, QWidget *parent) : AbstractEditor(mainWindow, subject, parent) {
    // setup oggetti grafici di questo editor specifico
    checkBoxUsato = new QCheckBox();
    boxNoleggiante = new QLineEdit();
    boxNoleggiatore = new QLineEdit();

    Noleggio* oggetto = dynamic_cast<Noleggio*>(subject);

    if (oggetto != nullptr) {
        checkBoxUsato->setChecked(oggetto->getUsato());
        boxNoleggiante->setText(QString::fromStdString(oggetto->getNoleggiante()));
        boxNoleggiatore->setText(QString::fromStdString(oggetto->getNoleggiatore()));
    }
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
    form->addRow("usato", checkBoxUsato);
    form->addRow("noleggiante", boxNoleggiante);
    form->addRow("noleggiatore", boxNoleggiatore);
    form->addRow("apply changes:", getButtonApply());

}

void EditorNoleggio::update()
{

}

void EditorNoleggio::create()
{

}
