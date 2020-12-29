#ifndef HT_AST_H
#define HT_AST_H

#include <stdlib.h>

typedef struct _astStruct
{
    enum {
        HT_AST_VAR_DEF,
        HT_AST_VAR,
        HT_AST_FUNCTION_CALL,
        HT_AST_STRING,
        HT_AST_COMPOUND_ST
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
    // Compound Source Tree
    struct _astStruct** _compoundStValue;
    size_t _compoundStSize;

} HT_AST;

HT_AST* HTAstInit(int type);

#endif