#include "PriceMatcher.h"



PriceMatcher::PriceMatcher(const float lowerBound, const float upperBound) : lowerBound(lowerBound), upperBound(upperBound) { }

bool PriceMatcher::hasMatch(const AbstractProduct& product) const {
    return (product.getPrezzo() > lowerBound && product.getPrezzo() < upperBound);
}
