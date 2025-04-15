#include "Array.hpp"




std::ostream& operator<<(std::ostream &os, const Array<T>& arr) {
    os << "[";
    for (unsigned int i = 0; i < arr.size(); ++i) {
        os << arr[i];
        if (i < arr.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}
`