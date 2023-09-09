#ifndef JSONCONVERTER_H
#define JSONCONVERTER_H

// direttive d'inclusione
#include "IConverter.h"

class JsonConverter : public IConverter {
public:
    JsonConverter(IReader& r);
    virtual QJsonObject getJsonFromObject(const AbstractProduct* item) const;
    virtual AbstractProduct* getObjectFromJson(const QJsonObject& json) const;
};

#endif
