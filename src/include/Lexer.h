#ifndef HT_LEXER_H
#define HT_LEXER_H

#include "Token.h"

typedef struct _lexerStruct {
    char _c;
    unsigned int _i;
    char* _con;
} HT_Lexer;

HT_Lexer* HTLexerInit(char* con);

void HTLexerAdvance(HT_Lexer* htlexer);

void HTLexerPassWhiteSpaces(HT_Lexer* htlexer);

HT_Token* HTLexerGetNextToken(HT_Lexer* htlexer);

HT_Token* HTLexerCollectString(HT_Lexer* htlexer);

HT_Token* HTLexerCollectId(HT_Lexer* htlexer);

char* HTLexerGetCurrentCharAsString(HT_Lexer* htlexer);

HT_Token* HTLexerAdvanceWithToken(HT_Lexer* htlexer, HT_Token* httoken);

#endif
