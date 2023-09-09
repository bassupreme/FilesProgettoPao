#ifndef MEMORY_H
#define MEMORY_H

// direttive d'inclusione
#include "Container.h"
#include "model/AbstractProduct.h"
#include "Filter.h"
#include <vector>

class Memory {
private:
    Container<const AbstractProduct*> container;
public:
    Memory();
    ~Memory();
    Memory& add(const AbstractProduct*);
    Memory& remove(const AbstractProduct*);
    std::vector<const AbstractProduct*> search(Filter*) const;
    bool empty() const;
    Memory& clear();
};

#endif
