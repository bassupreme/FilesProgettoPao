#ifndef EDITORVIRTUALE_H
#define EDITORVIRTUALE_H

#include "AbstractEditor.h"
#include <QLabel>

class EditorVirtuale : public AbstractEditor {
    Q_OBJECT
private:
    QLabel* editorVirtuale;
public:
    EditorVirtuale(MainWindow* mainWindow, const AbstractProduct* subject = nullptr, QWidget* parent = nullptr);
    void injectItem(const Virtuale&);
    virtual AbstractProduct* update() const;
    virtual AbstractProduct* create() const;
signals:
    void signalUpdated(const AbstractProduct*);
private slots:
    void emitSignalUpdate();
};

#endif
