#ifndef UTILS_H
#define UTILS_H

#include <type_traits>

namespace Utils
{
    template <class T, class U>
    bool is_same_type()
    {
        return std::is_same<T, U>::value;
    }
};

#endif