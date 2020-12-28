#ifndef HT_TOKEN_H
#define HT_TOKEN_H

typedef struct _tokenStruct {
    enum {
        HT_TOKEN_ID,
        HT_TOKEN_EQUALS,
        HT_TOKEN_LPAREN,
        HT_TOKEN_RPAREN,
        HT_TOKEN_SEMICOLON,
        HT_TOKEN_STRING
    } _htTokenType;

    char* _value;

} HT_Token;

HT_Token* HTTokenInit(int type, char* value);

#endif