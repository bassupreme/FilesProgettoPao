#ifndef IREADER_H
#define IREADER_H

// direttive d'inclusione
#include "AbstractProduct.h"
#include <QJsonObject>

class IReader {
public:
    virtual ~IReader() {}
    virtual AbstractProduct* read(const QJsonObject& jsonObject) const = 0;
};

#endif
