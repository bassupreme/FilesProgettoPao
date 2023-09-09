#ifndef ABSTRACTFILE_H
#define ABSTRACTFILE_H

// direttive di inclusione
#include <string>
#include <vector>
#include "model/AbstractProduct.h"

// dichiarazioni incomplete
class IConverter;

class AbstractFile {
private:
    std::string path;
public:
    virtual ~AbstractFile();
    AbstractFile(const std::string p);
    const std::string& getPath() const;
    virtual std::vector<AbstractProduct*> ReadFrom(const IConverter&) const = 0;
    virtual AbstractFile& WriteTo(const std::vector<const AbstractProduct*>&, const IConverter&) = 0;
};

#endif
