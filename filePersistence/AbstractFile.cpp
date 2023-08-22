#include "filePersistence/AbstractFile.h"


AbstractFile::~AbstractFile() { }

AbstractFile::AbstractFile(const std::string p) : path(p) {}

const std::string& AbstractFile::getPath() const { return path; } // implementazione di default
