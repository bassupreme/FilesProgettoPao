#ifndef ICONVERTER_H
#define ICONVERTER_H

// direttive d'inclusione
#include "model/AbstractProduct.h"
#include <string>
#include <QJsonObject>

// dichiarazioni incomplete
class IReader;

class IConverter {
private:
    IReader& reader;
public:
    virtual ~IConverter() {}
    IConverter(IReader& r) : reader(r) {}
    const IReader& getReader() const { return reader; }
    virtual QJsonObject getJsonFromObject(const AbstractProduct* item) const = 0;
    virtual AbstractProduct* getObjectFromJson(const QJsonObject& json) const = 0;
}; 

#endif
