#ifndef EDITORNOLEGGIO_H
#define EDITORNOLEGGIO_H

#include "AbstractEditor.h"
#include <QLabel>
#include <QCheckBox>

class EditorNoleggio : public AbstractEditor {
    Q_OBJECT
private:
    QCheckBox* checkBoxUsato;
    QLineEdit* boxNoleggiante;
    QLineEdit* boxNoleggiatore;
public:
    EditorNoleggio(MainWindow* mainWindow, AbstractProduct* subject = nullptr, QWidget* parent = nullptr);
    void injectItem(const Noleggio&);
    virtual AbstractProduct* update();
    virtual AbstractProduct* create();
signals:
    void signalUpdated(AbstractProduct*);
    void signalCreated(AbstractProduct*);
private slots:
    void emitSignalUpdate();
    void emitSignalCreate();
public slots:
    void updatedProduct(AbstractProduct*);
    void CreatedProduct(AbstractProduct*);

};

#endif // EDITORNOLEGGIO_H
