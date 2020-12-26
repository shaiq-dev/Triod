#include <stdio.h>

#include "include/Lexer.h"

int main(int argc, char* argv[]) {
    
    __Lexer__HT* __htlexer = HTLexerInit(
        "var name = \"shaiq\";"
        "print(\"Hello World\");"
    );

    __Token__HT* __httoken = (void*)0;

    while ((__httoken = HTLexerGetNextToken(__htlexer)) != (void*)0) {
        printf("TOKEN(%d, %s)\n",__httoken->__htTokenType, __httoken->__value);
    }

    return 0;
}