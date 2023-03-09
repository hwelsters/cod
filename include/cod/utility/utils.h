#ifndef UTILS_H
#define UTILS_H

#include <type_traits>

namespace Utils
{
    template <typename T, typename U>
    bool is_same_type() 
    { 
        std::cout << std::is_same<T, U>::value << "\n";
        return std::is_same<T, U>::value;
    }
};

#endif