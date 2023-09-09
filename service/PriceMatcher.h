#ifndef PRICEMATCHER_H
#define PRICEMATCHER_H

#include "IMatcher.h"

class PriceMatcher : public IMatcher {
private:
    const float lowerBound;
    const float upperBound;
public:
    PriceMatcher(const float lowerBound, const float upperBound);
    virtual bool hasMatch(const AbstractProduct&) const;
};

#endif
