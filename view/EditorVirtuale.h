#ifndef EDITORVIRTUALE_H
#define EDITORVIRTUALE_H

#include "AbstractEditor.h"
#include <QLabel>

class EditorVirtuale : public AbstractEditor {
    Q_OBJECT
private:
    QLabel* editorVirtuale;
public:
    EditorVirtuale(MainWindow* mainWindow, AbstractProduct* subject = nullptr, QWidget* parent = nullptr);
    void injectItem(const Virtuale&);
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

#endif // EDITORVIRTUALE_H
