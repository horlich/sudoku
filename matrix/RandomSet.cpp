#include "RandomSet.h"
#include <algorithm>
#include "onumber.h"

RandomSet::RandomSet()
{
    static ONumber::IntGenerator gen(1,9);
    while (size() < 9) {
        if (size() == 8) { // get the last value
            for (int i = 1; i <= 9; ++i) {
                if (contains(i)) continue;
                push_back(i);
                break;
            }
        } else {
            int val = gen();
            if (! contains(val)) {
                push_back(val);
            }
        }
    }
}


bool RandomSet::contains(int val) {
    return std::find(begin(), end(), val) != end();
}


std::ostream& operator<<(std::ostream& os, const RandomSet& rs) {
    os << "RandomSet(";
    for (size_t i = 0; i < rs.size(); ++i) {
        if (i > 0) os << ", ";
        os << rs.at(i);
    }
    os.put(')');
    return os;
}
