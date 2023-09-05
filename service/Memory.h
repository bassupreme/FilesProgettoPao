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
    std::vector<const AbstractProduct*> search(Filter*); // all'interno di search ci va il filtro. come parametro (ancora da implementare come classe
    bool empty() const;
    Memory& clear();
};

#endif // MEMORY_H
