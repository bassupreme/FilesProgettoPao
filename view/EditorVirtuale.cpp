#include "EditorVirtuale.h"
#include "model/Virtuale.h"
#include <QVBoxLayout>
#include <QFormLayout>

EditorVirtuale::EditorVirtuale(MainWindow *mainWindow, const AbstractProduct *subject, QWidget *parent) : AbstractEditor(mainWindow, subject, parent) {
    // setup oggetti grafici di questo editor specifico
    editorVirtuale = new QLabel("EDITOR VIRTUALE"); // DEBUG

    // CONNESSIONE SEGNALI E SLOT
    connect(this, SIGNAL(signalUpdated(const AbstractProduct*)), this,  SLOT(updatedProduct(const AbstractProduct*)));

}

void EditorVirtuale::injectItem(const Virtuale& product) {
    getBoxId()->setValue(product.getId());
    getBoxPrezzo()->setValue(product.getPrezzo());
    getBoxNome()->setText(QString::fromStdString(product.getNome()));
    getBoxImagePath()->setText(QString::fromStdString(product.getImagePath()));
    getBoxDescription()->setText(QString::fromStdString(product.getDescription()));
}

AbstractProduct* EditorVirtuale::update() const {
    return create();
}

AbstractProduct* EditorVirtuale::create() const {
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
