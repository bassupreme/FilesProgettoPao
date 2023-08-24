#ifndef EDITORNOLEGGIO_H
#define EDITORNOLEGGIO_H

#include "AbstractEditor.h"
#include <QLabel>
#include <QCheckBox>

class EditorNoleggio : public AbstractEditor {
private:
    QCheckBox* checkBoxUsato;
    QLineEdit* boxNoleggiante;
    QLineEdit* boxNoleggiatore;
public:
    EditorNoleggio(MainWindow* mainWindow, AbstractProduct* subject, QWidget* parent = nullptr);
    virtual void update();
    virtual void create();
    void injectItem(const Noleggio&);
private slots:
    void emitSignalUpdate();
    void emitSignalCreate();
public slots:
    void updatedProduct(AbstractProduct*);
    void CreatedProduct(AbstractProduct*);
signals:
    void signalUpdated(AbstractProduct*);
    void signalCreated(AbstractProduct*);
};

#endif // EDITORNOLEGGIO_H
