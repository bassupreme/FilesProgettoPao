#include "Memory.h"


Memory& Memory::add(const AbstractProduct* product) {
    container.add_back(product);
    return *this;
}

Memory &Memory::remove(const AbstractProduct* product) {
    container.remove(product);
    return *this;
}

std::vector<const AbstractProduct *> Memory::search(Filter* filtro) {
    std::vector<const AbstractProduct*> aux;
    Container<const AbstractProduct*>::Node* head = container.getHead();

    while(head != nullptr) {
        const AbstractProduct* t = head->getData();
        if (filtro->matchesAll(*t)) {
            aux.push_back(t);
        }
        head = head->getNext();
    }
    return aux;
}

bool Memory::empty() const {
    return (container.getHead() == nullptr);
}


Memory& Memory::clear() {
    container.clear();
    return *this;
}
