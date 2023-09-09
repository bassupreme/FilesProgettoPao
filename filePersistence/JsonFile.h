#ifndef JSONFILE_H
#define JSONFILE_H

// direttive d'inclusione
#include <string> 
#include "AbstractFile.h"
#include "model/AbstractProduct.h"

class JsonFile : public AbstractFile {

public:
    JsonFile(const std::string p);
    virtual std::vector<AbstractProduct*> ReadFrom(const IConverter&) const;
    virtual JsonFile& WriteTo(const std::vector<const AbstractProduct*>&, const IConverter&);
};

#endif
