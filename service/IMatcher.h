#ifndef IMATCHER_H
#define IMATCHER_H

#include "model/AbstractProduct.h"

class IMatcher { // interfaccia IMatcher
public:
    virtual ~IMatcher() {}
    virtual bool hasMatch(const AbstractProduct&) const = 0;
};

#endif // IMATCHER_H
