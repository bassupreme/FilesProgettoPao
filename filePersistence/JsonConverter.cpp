#include "JsonConverter.h"
#include "JsonVisitor.h"
#include "JsonReader.h"

JsonConverter::JsonConverter(IReader* r) : IConverter(r) { } // implementazione costruttore di default


QJsonObject JsonConverter::getJsonFromObject(const AbstractProduct* item) const {
    // logica per convertire un oggetto da AbstractProduct* a string (QJsonObject)

    JsonVisitor jsonVisitor;
    item->accept(jsonVisitor);
    return jsonVisitor.getJsonObject();
}

AbstractProduct* JsonConverter::getObjectFromJson(const QJsonObject& json) const {
    // logica per convertire un oggetto da string (QJsonObject) a AbstractProduct*
    return (getReader())->read(json);
}
