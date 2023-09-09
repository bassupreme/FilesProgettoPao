// direttive di inclusione
#include "JsonVisitor.h"
#include "model/Fisico.h"
#include "model/Virtuale.h"
#include "model/Noleggio.h"

void JsonVisitor::visit(const Fisico& f) {
    QJsonObject fisico_object;
    fisico_object.insert("type", QJsonValue::fromVariant("fisico"));
    fisico_object.insert("id", QJsonValue::fromVariant(f.getId()));
    fisico_object.insert("prezzo", QJsonValue::fromVariant(f.getPrezzo()));
    fisico_object.insert("name", QJsonValue::fromVariant(f.getNome().c_str()));
    fisico_object.insert("description", QJsonValue::fromVariant(f.getDescription().c_str()));
    fisico_object.insert("imagePath", QJsonValue::fromVariant(f.getImagePath().c_str()));
    fisico_object.insert("usato", QJsonValue::fromVariant(f.getUsato()));
    jsonObject = fisico_object;
}

void JsonVisitor::visit(const Virtuale& f) {
    QJsonObject fisico_object;
    fisico_object.insert("type", QJsonValue::fromVariant("virtuale"));
    fisico_object.insert("id", QJsonValue::fromVariant(f.getId()));
    fisico_object.insert("prezzo", QJsonValue::fromVariant(f.getPrezzo()));
    fisico_object.insert("name", QJsonValue::fromVariant(f.getNome().c_str()));
    fisico_object.insert("description", QJsonValue::fromVariant(f.getDescription().c_str()));
    fisico_object.insert("imagePath", QJsonValue::fromVariant(f.getImagePath().c_str()));
    jsonObject = fisico_object;
}

void JsonVisitor::visit(const Noleggio& f) {
    QJsonObject fisico_object;
    fisico_object.insert("type", QJsonValue::fromVariant("noleggio"));
    fisico_object.insert("id", QJsonValue::fromVariant(f.getId()));
    fisico_object.insert("prezzo", QJsonValue::fromVariant(f.getPrezzo()));
    fisico_object.insert("name", QJsonValue::fromVariant(f.getNome().c_str()));
    fisico_object.insert("description", QJsonValue::fromVariant(f.getDescription().c_str()));
    fisico_object.insert("imagePath", QJsonValue::fromVariant(f.getImagePath().c_str()));
    fisico_object.insert("usato", QJsonValue::fromVariant(f.getUsato()));
    fisico_object.insert("noleggiatore", QJsonValue::fromVariant(f.getNoleggiatore().c_str()));
    fisico_object.insert("noleggiante", QJsonValue::fromVariant(f.getNoleggiante().c_str()));
    jsonObject = fisico_object;
}

QJsonObject JsonVisitor::getJsonObject() {
    return jsonObject;
}
