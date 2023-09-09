#include "SubstringMatcher.h"


bool SubstringMatcher::matches(const AbstractProduct & product) const {
    const std::string& stringa_totale = product.getNome();
    int found =  stringa_totale.find(substring, 0);

    if (found == -1) return false;
    return true;
}

SubstringMatcher::SubstringMatcher(const std::string& substring) : substring(substring) {}

bool SubstringMatcher::hasMatch(const AbstractProduct& product) const {
    return matches(product);
}
