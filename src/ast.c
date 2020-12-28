#include <stdlib.h>

#include "include/Triod.h"
#include "include/Ast.h"

HT_AST* HTAstInit(int type) {
    HT_AST* htast = calloc(1, sizeof(struct _astStruct));
    htast->_type = type;

    htast->_varDefVarName = __voidNull;
    htast->_varDefValue = __voidNull;
    htast->_varName = __voidNull;
    htast->_functionCallName = __voidNull;
    htast->_functionCallArgs = __voidNull;
    htast->_functionCallArgsSize = __voidNull;
    htast->_stringValue = __voidNull;

    return htast;
}