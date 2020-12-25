#include <stdlib.h>
#include "include/Token.h"

__Token__HT* HTTokenInit(int __type, char* __value) {
    __Token__HT* __httoken = calloc(1, sizeof(struct _tokenStruct));
    __httoken->__htTokenType = __type;
    __httoken->__value = __value;

    return __httoken;
}