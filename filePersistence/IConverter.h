#ifndef ICONVERTER_H
#define ICONVERTER_H

// direttive d'inclusione
#include "AbstractProduct.h"
#include <string>
#include <QJsonObject>

// dichiarazioni incomplete
class IReader;

class IConverter { // rinominare ad AbstractConverter (in quanto è una classe astratta)
private:
    IReader* reader;
public:
    virtual ~IConverter() {}
    IConverter(IReader* r) : reader(r) {}
    const IReader* getReader() const { return reader; } // implementazione di default
    virtual QJsonObject getJsonFromObject(const AbstractProduct* item) const = 0;
    virtual AbstractProduct* getObjectFromJson(const QJsonObject& json) const = 0;
}; 

#endif
