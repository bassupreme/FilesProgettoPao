#ifndef JSONREADER_H
#define JSONREADER_H

// direttive d'inclusione
#include "IReader.h"
#include <QJsonObject>

class JsonReader : public IReader {
private:
    AbstractProduct* readFisico(const QJsonObject& jsonObject) const;
    AbstractProduct* readVirtuale(const QJsonObject& jsonObject) const;
    AbstractProduct* readNoleggio(const QJsonObject& jsonObject) const;
public:
    virtual AbstractProduct* read(const QJsonObject& jsonObject) const;
 
};
#endif
