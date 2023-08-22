#ifndef IFILE_H
#define IFILE_H

// direttive di inclusione
#include <string>
#include <vector>
#include "AbstractProduct.h"

// dichiarazioni incomplete
class IConverter; 

class IFile { // rinominare ad AbstractFile
private:
    std::string path; // ogni file ha un percorso
public:
    virtual ~IFile(); // distruttore virtuale
    IFile(const std::string p);
    const std::string& getPath() const; // implementazione di default
    virtual std::vector<AbstractProduct*> ReadFrom(const IConverter&) = 0; // serializzazione
    virtual IFile& WriteTo(const std::vector<AbstractProduct*>&, const IConverter&) = 0; // deserializzazione
};

#endif
