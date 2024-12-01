#ifndef MYLIB
    #define MYLIB

    #include <stdlib.h>
    #include <stdio.h>

    #define MAX(a, b) (a > b ? a : b)
    #define DEFINE_TRIVIAL_CLEANUP_FUNC(type, func)             \
        static inline void func##p(type *p) {                   \
                if (*p)                                         \
                        func(*p);                               \
        }                                                       \

    #include "MyHash.h"
    #include "my_radix.h"


#endif