#ifndef ABSTRACTFILE_H
#define ABSTRACTFILE_H

// direttive di inclusione
#include <string>
#include <vector>
#include "model/AbstractProduct.h"

// dichiarazioni incomplete
class IConverter; 

class AbstractFile { // rinominare ad AbstractFile
private:
    std::string path; // ogni file ha un percorso
public:
    virtual ~AbstractFile(); // distruttore virtuale
    AbstractFile(const std::string p);
    const std::string& getPath() const; // implementazione di default
    virtual std::vector<AbstractProduct*> ReadFrom(const IConverter&) = 0; // serializzazione
    virtual AbstractFile& WriteTo(const std::vector<const AbstractProduct*>&, const IConverter&) = 0; // deserializzazione
};

#endif
