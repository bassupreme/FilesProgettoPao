#include "Memory.h"

Memory::Memory() { }

Memory::~Memory() {}

Memory& Memory::add(const AbstractProduct* product) {
    container.add_back(product);
    return *this;
}

Memory &Memory::remove(const AbstractProduct* product) {
    container.remove(product);
    // DEBUG
    std::cout << "size container: " << container.getSize() << std::endl;
    return *this;
}

std::vector<const AbstractProduct *> Memory::search(Filter* filtro) {
    std::vector<const AbstractProduct*> aux;
    Container<const AbstractProduct*>::const_iterator cit = container.begin();

    while(cit != container.end()) {
        const AbstractProduct* t = *cit;
        if (filtro->matchesAll(*t)) {
            aux.push_back(t);
        }
        cit++;
    }
    return aux;
}

bool Memory::empty() const {
    return container.empty();
}


Memory& Memory::clear() {
    container.clear();
    return *this;
}
