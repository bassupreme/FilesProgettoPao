#include "Buffer.h"


void Buffer::destroy(const std::map<unsigned int, AbstractProduct*>& b) {
    std::map<unsigned int, AbstractProduct*>::const_iterator it;
    for(it = b.begin(); it != b.end(); it++) {
        delete it->second;
    }
}

Buffer::Buffer() {}

Buffer::~Buffer() {
    destroy(memoryBuffer);
}

bool Buffer::exists(const unsigned int key) const {
    std::map<unsigned int, AbstractProduct*>::const_iterator it = memoryBuffer.find(key);
    return (it != memoryBuffer.end());
}

unsigned int Buffer::getSize() const {
    return memoryBuffer.size();
}


Buffer& Buffer::insert(const unsigned int key, AbstractProduct* product) {
    memoryBuffer[key] = product;
    return *this;
}


Buffer& Buffer::remove(const unsigned int key) {
    AbstractProduct* p = memoryBuffer[key];
    delete p;
    memoryBuffer.erase(key);
    return *this;
}

const AbstractProduct* Buffer::get(const unsigned int key) const {
    std::map<unsigned int, AbstractProduct*>::const_iterator it = memoryBuffer.find(key);

    if (it == memoryBuffer.end()) {
        throw std::out_of_range("id non esistente");
    }
    return it->second;
}

Buffer& Buffer::modify(const unsigned int key, AbstractProduct* product) {
    memoryBuffer[key] = product;
    return *this;
}

const std::map<unsigned int, AbstractProduct*>& Buffer::getMemoryBuffer() const {
    return memoryBuffer;
}

void Buffer::load(const std::vector<AbstractProduct*>& aux) {
    for(std::vector<AbstractProduct*>::const_iterator cit = aux.begin(); cit != aux.end(); cit++) {
        memoryBuffer[(*cit)->getId()] = (*cit);
    }
}

std::vector<const AbstractProduct*> Buffer::readAll() const {
    std::vector<const AbstractProduct*> aux;
    for(auto it = memoryBuffer.begin(); it != memoryBuffer.end(); it++) {
        aux.push_back(it->second);
    }

    return aux;
}

void Buffer::clear() {
    destroy(memoryBuffer);
    memoryBuffer.erase(memoryBuffer.begin(), memoryBuffer.end());
}

bool Buffer::empty() const {
    return memoryBuffer.empty();
}
