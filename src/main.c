#include <stdio.h>

#include "include/Lexer.h"

int main(int argc, char* argv[]) {
    
    HT_Lexer* htlexer = HTLexerInit(
        "var name = \"shaiq\";"
        "print(\"Hello World\");"
    );

    HT_Token* httoken = (void*)0;

    while ((httoken = HTLexerGetNextToken(htlexer)) != (void*)0) {
        printf("TOKEN(%d, %s)\n",httoken->_htTokenType, httoken->_value);
    }

    return 0;
}