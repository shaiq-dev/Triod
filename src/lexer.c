#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "include/Lexer.h"
#include "include/Defs.h"


__Lexer__HT* HTLexerInit(char* __con) {
    __Lexer__HT* __lexer = calloc(1, sizeof(struct _lexerStruct));
    __lexer->_con = __con;
    __lexer->_i = 0;
    __lexer->_c = __con[__lexer->_i];

    return __lexer;
}

void HTLexerAdvance(__Lexer__HT* __htlexer) {
    if (__htlexer->_c != __NullChar && __htlexer->_i < strlen(__htlexer->_con)) {
        __htlexer->_i += 1;
        __htlexer->_c = __htlexer->_con[__htlexer->_i];
    }
}

void HTLexerPassWhiteSpaces(__Lexer__HT* __htlexer) {
    while (__htlexer->_c == __WhiteSpace || __htlexer->_c == __lexerEncounterBreak) {
        HTLexerAdvance(__htlexer);
    } 
}

__Token__HT* HTLexerAdvanceWithToken(__Lexer__HT* __htlexer, __Token__HT* __httoken) {
    HTLexerAdvance(__htlexer);
    return __httoken;
}

__Token__HT* HTLexerGetNextToken(__Lexer__HT* __htlexer) {
    while (__htlexer->_c != __NullChar && __htlexer->_i < strlen(__htlexer->_con)) {
        
        if (__htlexer->_c == __WhiteSpace || __htlexer->_c == __lexerEncounterBreak)
            HTLexerPassWhiteSpaces(__htlexer);

        // Parse String
        if (__htlexer->_c == '"')
            return HTLexerCollectString(__htlexer);

        // Parse Id
        if (isalnum(__htlexer->_c))
            return HTLexerCollectId(__htlexer);
        
        switch (__htlexer->_c) {
            case '=' : 
                return HTLexerAdvanceWithToken(__htlexer, HTTokenInit(__TOKEN_HT_EQUALS, HTLexerGetCurrentCharAsString(__htlexer)));
                break;
            case '(' : 
                return HTLexerAdvanceWithToken(__htlexer, HTTokenInit(__TOKEN_HT_LPAREN, HTLexerGetCurrentCharAsString(__htlexer)));
                break;
            case ')' : 
                return HTLexerAdvanceWithToken(__htlexer, HTTokenInit(__TOKEN_HT_RPAREN, HTLexerGetCurrentCharAsString(__htlexer)));
                break;
            case ';' : 
                return HTLexerAdvanceWithToken(__htlexer, HTTokenInit(__TOKEN_HT_SEMICOLON, HTLexerGetCurrentCharAsString(__htlexer)));
                break;

        }
    }

    return (void*)0;
}

__Token__HT* HTLexerCollectId(__Lexer__HT* __htlexer) {

    char* __val = calloc(1, sizeof(char));
    __val[0] = __NullChar;

    while(isalnum(__htlexer->_c)) {
        char* _cur = HTLexerGetCurrentCharAsString(__htlexer);
        __val = realloc(__val, (strlen(__val) + strlen(_cur) + 1) * sizeof(char));
        strcat(__val, _cur);

        HTLexerAdvance(__htlexer);
    }
    
    return HTTokenInit(__TOKEN_HT_ID, __val);
}

__Token__HT* HTLexerCollectString(__Lexer__HT* __htlexer) {
    // Skip the first quote
    HTLexerAdvance(__htlexer);
    char* __strVal = calloc(1, sizeof(char));
    __strVal[0] = __NullChar;

    while(__htlexer->_c != '"') {
        char* _cur = HTLexerGetCurrentCharAsString(__htlexer);
        __strVal = realloc(__strVal, (strlen(__strVal) + strlen(_cur) + 1) * sizeof(char));
        strcat(__strVal, _cur);

        HTLexerAdvance(__htlexer);
    }
    // Skip last quote
    HTLexerAdvance(__htlexer);

    return HTTokenInit(__TOKEN_HT_STRING, __strVal);
}

char* HTLexerGetCurrentCharAsString(__Lexer__HT* __htlexer) {
    char* __str = calloc(2, sizeof(char));
    __str[0] = __htlexer->_c;
    __str[1] = __NullChar;

    return __str;
}