#ifndef LEXER_HT
#define LEXER_HT

#include "Token.h"

typedef struct _lexerStruct {
    char _c;
    unsigned int _i;
    char* _con;
} __Lexer__HT;

__Lexer__HT* HTLexerInit(char* __con);

void HTLexerAdvance(__Lexer__HT* __htlexer);

void HTLexerPassWhiteSpaces(__Lexer__HT* __htlexer);

__Token__HT* HTLexerGetNextToken(__Lexer__HT* __htlexer);

__Token__HT* HTLexerCollectString(__Lexer__HT* __htlexer);

__Token__HT* HTLexerCollectId(__Lexer__HT* __htlexer);

char* HTLexerGetCurrentCharAsString(__Lexer__HT* __htlexer);

__Token__HT* HTLexerAdvanceWithToken(__Lexer__HT* __htlexer, __Token__HT* __httoken);

#endif
