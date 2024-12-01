#ifndef MYLIB
    #define MYLIB

    #include <stdlib.h>

    #define MAX(a, b) (a > b ? a : b)
    #define DEFINE_TRIVIAL_CLEANUP_FUNC(type, func)             \
        static inline void func##p(type *p) {                   \
                if (*p)                                         \
                        func(*p);                               \
        }                                                       \
        struct __useless_struct_to_allow_trailing_semicolon__

    #include "MyHash.h"
    #include "my_radix.h"


#endif