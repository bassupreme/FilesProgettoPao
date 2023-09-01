#include "EditorVirtuale.h"
#include "model/Virtuale.h"
#include <QVBoxLayout>
#include <QFormLayout>

EditorVirtuale::EditorVirtuale(MainWindow *mainWindow, const AbstractProduct *subject, QWidget *parent) : AbstractEditor(mainWindow, subject, parent) {
    // setup oggetti grafici di questo editor specifico
    editorVirtuale = new QLabel("EDITOR VIRTUALE");

    /*
    // set up layout verticale
    QVBoxLayout* vbox = new QVBoxLayout(this);
    vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    // setup form layout
    QFormLayout* form = new QFormLayout();
    form->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);
    vbox->addLayout(form);


    // aggiunta elementi al form
    form->addRow("id:", getBoxId());
    form->addRow("prezzo:", getBoxPrezzo());
    form->addRow("nome:", getBoxNome());
    form->addRow("imagePath:", getBoxImagePath());
    form->addRow("descrizione:", getBoxDescription());
    */
    // form->addRow("apply changes:", getButtonApply());

    // connect(getButtonApply(), SIGNAL(clicked()), this, SLOT(emitSignalUpdate()));
    connect(this, SIGNAL(signalUpdated(const AbstractProduct*)), this,  SLOT(updatedProduct(const AbstractProduct*)));

}

void EditorVirtuale::injectItem(const Virtuale& product) {

    // settare i campi delle box
    getBoxId()->setValue(product.getId());
    getBoxPrezzo()->setValue(product.getPrezzo());
    getBoxNome()->setText(QString::fromStdString(product.getNome()));
    getBoxImagePath()->setText(QString::fromStdString(product.getImagePath()));
    getBoxDescription()->setText(QString::fromStdString(product.getDescription()));
}

AbstractProduct* EditorVirtuale::update() {
    return create();
}

AbstractProduct* EditorVirtuale::create() {
    return new Virtuale(getBoxId()->value(),
               getBoxPrezzo()->value(),
               getBoxNome()->text().toStdString(),
               getBoxImagePath()->text().toStdString(),
               getBoxDescription()->toPlainText().toStdString()
               );

}

void EditorVirtuale::emitSignalUpdate() {
    emit signalUpdated(getSubject());
}

void EditorVirtuale::updatedProduct(const AbstractProduct* product) {
    // richiamare la funzione update
    std::cout << "EditorVirtuale::updatedProduct()" << std::endl;
    AbstractProduct* aux = update();

    Buffer* buffer = getMainWindow()->getBuffer();
    buffer->remove(product->getId());
    buffer->insert(aux->getId(), aux);

    Memory& memory = getMainWindow()->getMemory();
    memory.remove(product);
    memory.add(aux);

    /*
    std::vector<AbstractProduct*>& memoria = getMainWindow()->getMemory();
    std::vector<AbstractProduct*>::const_iterator cit = memoria.begin();

    while ((*cit) != product) {
        cit++;
    }

    memoria.erase(cit);
    memoria.push_back(aux);
    delete product;
    */
    getMainWindow()->clearResults();
    getMainWindow()->search(nullptr);
}
