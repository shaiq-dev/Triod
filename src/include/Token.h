#ifndef TOKEN_HT
#define TOKEN_HT

typedef struct _tokenStruct {
    enum {
        __TOKEN_HT_ID,
        __TOKEN_HT_EQUALS,
        __TOKEN_HT_LPAREN,
        __TOKEN_HT_RPAREN,
        __TOKEN_HT_SEMICOLON,
        __TOKEN_HT_STRING
    } __htTokenType;

    char* __value

} __Token__HT;

__Token__HT* InitHTToken(int __type, char* __value);

#endif