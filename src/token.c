#include <stdlib.h>
#include "include/Token.h"

HT_Token* HTTokenInit(int type, char* value) {
    HT_Token* httoken = calloc(1, sizeof(struct _tokenStruct));
    httoken->_htTokenType = type;
    httoken->_value = value;

    return httoken;
}