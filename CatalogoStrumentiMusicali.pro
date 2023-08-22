QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    filePersistence/AbstractFile.cpp \
    filePersistence/JsonConverter.cpp \
    filePersistence/JsonFile.cpp \
    filePersistence/JsonReader.cpp \
    filePersistence/JsonVisitor.cpp \
    main.cpp \
    model/AbstractProduct.cpp \
    model/Fisico.cpp \
    model/Noleggio.cpp \
    model/Virtuale.cpp \
    service/Buffer.cpp \
    service/Filter.cpp \
    service/Memory.cpp \
    service/PriceMatcher.cpp \
    service/SubstringMatcher.cpp \
    view/FilterWidget.cpp \
    view/ItemRenderer.cpp \
    view/ListItem.cpp \
    view/ResultsWidget.cpp \
    view/TestProductEditor.cpp \
    view/mainwindow.cpp

HEADERS += \
    filePersistence/AbstractFile.h \
    filePersistence/IConverter.h \
    filePersistence/IReader.h \
    filePersistence/JsonConverter.h \
    filePersistence/JsonFile.h \
    filePersistence/JsonReader.h \
    filePersistence/JsonVisitor.h \
    model/AbstractProduct.h \
    model/Fisico.h \
    model/IConstVisitor.h \
    model/IVisitor.h \
    model/Noleggio.h \
    model/Virtuale.h \
    service/Buffer.h \
    service/Container.h \
    service/Filter.h \
    service/IMatcher.h \
    service/Memory.h \
    service/PriceMatcher.h \
    service/SubstringMatcher.h \
    view/FilterWidget.h \
    view/ItemRenderer.h \
    view/ListItem.h \
    view/ResultsWidget.h \
    view/TestProductEditor.h \
    view/mainwindow.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
