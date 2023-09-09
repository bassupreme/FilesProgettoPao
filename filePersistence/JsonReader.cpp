// direttive d'inclusione
#include <QJsonValue>
#include "JsonReader.h"
#include "model/AbstractProduct.h"
#include "model/Fisico.h"
#include "model/Virtuale.h"
#include "model/Noleggio.h"

// l'implementazione del costruttore di default va bene 

AbstractProduct* JsonReader::read(const QJsonObject& jsonObject) const {
    QJsonValue type = jsonObject.value("type");
    if (type.isUndefined()) {
        std::cout << "Missing item type." << std::endl;
    }
    if (type.toString().compare("virtuale") == 0) {
        return readVirtuale(jsonObject);
    }
    else if (type.toString().compare("fisico") == 0) {
        return readFisico(jsonObject);
    }
    else if (type.toString().compare("noleggio") == 0) {
        return readNoleggio(jsonObject);
    } else {
        std::cout << "Unknown item type." << std::endl;
    }
    return nullptr;
}

// METODI PRIVATI
AbstractProduct* JsonReader::readFisico(const QJsonObject& jsonObject) const {
    return new Fisico(
                jsonObject.value("id").toInt(),
                jsonObject.value("prezzo").toDouble(),
                jsonObject.value("name").toString().toStdString(),
                jsonObject.value("imagePath").toString().toStdString(),
                jsonObject.value("description").toString().toStdString(),
                jsonObject.value("usato").toBool());
}

AbstractProduct* JsonReader::readVirtuale(const QJsonObject& jsonObject) const {
    return new Virtuale(
                jsonObject.value("id").toInt(),
                jsonObject.value("prezzo").toDouble(),
                jsonObject.value("name").toString().toStdString(),
                jsonObject.value("imagePath").toString().toStdString(),
                jsonObject.value("description").toString().toStdString());
}

AbstractProduct* JsonReader::readNoleggio(const QJsonObject& jsonObject) const {
    return new Noleggio(
                jsonObject.value("id").toInt(),
                jsonObject.value("prezzo").toDouble(),
                jsonObject.value("name").toString().toStdString(),
                jsonObject.value("imagePath").toString().toStdString(),
                jsonObject.value("description").toString().toStdString(),
                jsonObject.value("usato").toBool(),
                jsonObject.value("noleggiatore").toString().toStdString(),
                jsonObject.value("noleggiante").toString().toStdString());
}
