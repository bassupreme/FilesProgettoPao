#ifndef BUFFER_H
#define BUFFER_H

#include <map>
#include <vector>
#include "model/AbstractProduct.h"

class Buffer {
private:
    std::map<unsigned int, AbstractProduct*> memoryBuffer;
    static void destroy(const std::map<unsigned int, AbstractProduct*>&);
public:
    Buffer();
    ~Buffer();
    bool exists(const unsigned int) const;
    Buffer& insert(const unsigned int, AbstractProduct*);
    Buffer& remove(const unsigned int);
    const AbstractProduct* get(const unsigned int) const;
    Buffer& modify(const unsigned int, AbstractProduct*);
    const std::map<unsigned int, AbstractProduct*>& getMemoryBuffer() const;
    void load(const std::vector<AbstractProduct*>&);
    std::vector<AbstractProduct*> readAll() const;

    void clear();
    bool empty() const;
};

#endif
