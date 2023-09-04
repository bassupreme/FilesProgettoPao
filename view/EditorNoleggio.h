#ifndef EDITORNOLEGGIO_H
#define EDITORNOLEGGIO_H

#include "EditorFisico.h"
#include <QLabel>
#include <QCheckBox>

class EditorNoleggio : public EditorFisico {
    Q_OBJECT
private:
    QCheckBox* checkBoxUsato;
    QLineEdit* boxNoleggiante;
    QLineEdit* boxNoleggiatore;
public:
    EditorNoleggio(MainWindow* mainWindow, const AbstractProduct* subject = nullptr, QWidget* parent = nullptr);
    void injectItem(const Noleggio&);
    virtual AbstractProduct* update();
    virtual AbstractProduct* create();
signals:
    void signalUpdated(const AbstractProduct*);
private slots:
    virtual void emitSignalUpdate();
public slots:
    virtual void updatedProduct(const AbstractProduct*);
};

#endif // EDITORNOLEGGIO_H
