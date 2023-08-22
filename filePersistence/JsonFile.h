#ifndef JSONFILE_H
#define JSONFILE_H

// direttive d'inclusione
#include <string> 
#include "AbstractFile.h"
#include "model/AbstractProduct.h"

class JsonFile : public AbstractFile {

public:
    JsonFile(const std::string p); // implementazione specifica
    virtual std::vector<AbstractProduct*> ReadFrom(const IConverter&); // implementazione specifica
    virtual JsonFile& WriteTo(const std::vector<AbstractProduct*>&, const IConverter&); // implementazione specifica
};

#endif
