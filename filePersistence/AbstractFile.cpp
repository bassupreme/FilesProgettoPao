#include "IFile.h"


IFile::~IFile() { }

IFile::IFile(const std::string p) : path(p) {}

const std::string& IFile::getPath() const { return path; } // implementazione di default
