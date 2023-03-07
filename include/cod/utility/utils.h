#ifndef UTILS_H
#define UTILS_H

#include <type_traits>

namespace Utils
{
    template <class T, class U>
    static bool is_same_type(T t, U u)
    {
        return std::is_same<T, U>::value;
    }
};

#endif