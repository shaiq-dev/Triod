#ifndef HT_AST_H
#define HT_AST_H

#include <stdlib.h>

typedef struct _astSruct
{
    enum {
        HT_AST_VAR_DEF,
        HT_AST_VAR,
        HT_AST_FUNCTION_CALL,
        HT_AST_STRING
    } _type;

    // Variable Definations
    char* _varDefVarName;
    struct _astStruct* _varDefValue;
    // Variable
    char* _varName;
    // Function Call
    char* _functionCallName;
    struct _astStruct* _functionCallArgs;
    size_t _functionCallArgsSize;
    // String
    char* _stringValue;

} HT_AST;

HT_AST* HTAstInit(int type);

#endif