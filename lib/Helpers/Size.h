
#ifndef _SIZE_H
#define _SIZE_H

#include "cstddef"


template<typename T, std::size_t sz>
std::size_t size(T(&)[sz]) {
    return sz;
}

#endif
