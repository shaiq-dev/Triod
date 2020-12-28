#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "include/Lexer.h"
#include "include/Triod.h"


HT_Lexer* HTLexerInit(char* con) {
    HT_Lexer* htlexer = calloc(1, sizeof(struct _lexerStruct));
    htlexer->_con = con;
    htlexer->_i = 0;
    htlexer->_c = con[htlexer->_i];

    return htlexer;
}

void HTLexerAdvance(HT_Lexer* htlexer) {
    if (htlexer->_c != __nullChar && htlexer->_i < strlen(htlexer->_con)) {
        htlexer->_i += 1;
        htlexer->_c = htlexer->_con[htlexer->_i];
    }
}

void HTLexerPassWhiteSpaces(HT_Lexer* htlexer) {
    while (htlexer->_c == __whiteSpace || htlexer->_c == __newLineBreak) {
        HTLexerAdvance(htlexer);
    } 
}

HT_Token* HTLexerAdvanceWithToken(HT_Lexer* htlexer, HT_Token* __httoken) {
    HTLexerAdvance(htlexer);
    return __httoken;
}

HT_Token* HTLexerGetNextToken(HT_Lexer* htlexer) {
    while (htlexer->_c != __nullChar && htlexer->_i < strlen(htlexer->_con)) {
        
        if (htlexer->_c == __whiteSpace || htlexer->_c == __newLineBreak)
            HTLexerPassWhiteSpaces(htlexer);

        // Parse String
        if (htlexer->_c == '"')
            return HTLexerCollectString(htlexer);

        // Parse Id
        if (isalnum(htlexer->_c))
            return HTLexerCollectId(htlexer);
        
        switch (htlexer->_c) {
            case '=' : 
                return HTLexerAdvanceWithToken(htlexer, HTTokenInit(HT_TOKEN_EQUALS, HTLexerGetCurrentCharAsString(htlexer)));
                break;
            case '(' : 
                return HTLexerAdvanceWithToken(htlexer, HTTokenInit(HT_TOKEN_LPAREN, HTLexerGetCurrentCharAsString(htlexer)));
                break;
            case ')' : 
                return HTLexerAdvanceWithToken(htlexer, HTTokenInit(HT_TOKEN_RPAREN, HTLexerGetCurrentCharAsString(htlexer)));
                break;
            case ';' : 
                return HTLexerAdvanceWithToken(htlexer, HTTokenInit(HT_TOKEN_SEMICOLON, HTLexerGetCurrentCharAsString(htlexer)));
                break;

        }
    }

    return (void*)0;
}

HT_Token* HTLexerCollectId(HT_Lexer* htlexer) {

    char* _val = calloc(1, sizeof(char));
    _val[0] = __nullChar;

    while(isalnum(htlexer->_c)) {
        char* _cur = HTLexerGetCurrentCharAsString(htlexer);
        _val = realloc(_val, (strlen(_val) + strlen(_cur) + 1) * sizeof(char));
        strcat(_val, _cur);

        HTLexerAdvance(htlexer);
    }
    
    return HTTokenInit(HT_TOKEN_ID, _val);
}

HT_Token* HTLexerCollectString(HT_Lexer* htlexer) {
    // Skip the first quote
    HTLexerAdvance(htlexer);
    char* _strVal = calloc(1, sizeof(char));
    _strVal[0] = __nullChar;

    while(htlexer->_c != '"') {
        char* _cur = HTLexerGetCurrentCharAsString(htlexer);
        _strVal = realloc(_strVal, (strlen(_strVal) + strlen(_cur) + 1) * sizeof(char));
        strcat(_strVal, _cur);

        HTLexerAdvance(htlexer);
    }
    // Skip last quote
    HTLexerAdvance(htlexer);

    return HTTokenInit(HT_TOKEN_STRING, _strVal);
}

char* HTLexerGetCurrentCharAsString(HT_Lexer* htlexer) {
    char* _str = calloc(2, sizeof(char));
    _str[0] = htlexer->_c;
    _str[1] = __nullChar;

    return _str;
}