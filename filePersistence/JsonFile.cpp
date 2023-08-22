// direttive d'inclusione
#include "JsonFile.h"
#include "JsonConverter.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QJsonDocument>

JsonFile::JsonFile(const std::string p) : AbstractFile(p) {} // implementazione costruttore di default

std::vector<AbstractProduct*> JsonFile::ReadFrom(const IConverter& converter) {
    std::vector<AbstractProduct*> aux;

    // implementare la serializzazione
    QFile json_file(QString::fromStdString(getPath()));
    if(!json_file.open(QFile::ReadOnly)) {
        std::cout << "impossibile aprire il file in lettura" << std::endl;
        return aux;
    }
    QByteArray data = json_file.readAll();
    json_file.close();
    QJsonDocument document = QJsonDocument::fromJson(data);
    QJsonArray json_items = document.array();

    for (const QJsonValue& value: json_items) {
        QJsonObject json_object = value.toObject();
        aux.push_back(converter.getObjectFromJson(json_object));
    }
    return aux;
}

JsonFile& JsonFile::WriteTo(const std::vector<AbstractProduct*>& prodotti, const IConverter& converter) { // covarianza sul tipo di ritorno
    QJsonArray jsonItems;

    for(std::vector<AbstractProduct*>::const_iterator it = prodotti.begin(); it!= prodotti.end(); it++) {
        QJsonObject jsonObject = converter.getJsonFromObject(*it);
        jsonItems.push_back(jsonObject);
    }

    QJsonDocument document(jsonItems);
    const std::string& s = getPath();
    // creazione e setup del file
    QFile json_file;
    json_file.setFileName(QString::fromStdString(s));

    if (!json_file.open(QIODevice::WriteOnly)) {
        std::cout << "Non si riesce ad aprire il file" << endl;
    } else {
        json_file.write(document.toJson());
        std::cout << "Dataset salvato correttamente" << endl;
        json_file.flush();
    }
    json_file.close();

    return *this;
} // implementazione specifica
