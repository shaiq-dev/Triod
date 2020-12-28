#include <stdio.h>
#include <stdlib.h>

#include "include/Triod.h"
#include "include/Lexer.h"
#include "include/Parser.h"

HT_PARSER* HTParserInit(HT_Lexer* htlexer){
    HT_PARSER* htparser = calloc(1, sizeof(struct _parserStruct)); 
    htparser->_htlexer = htlexer;
    htparser->_curToken = HTLexerGetNextToken(htlexer);

    return htparser;
}

void HTParserEat(HT_PARSER* htparser, int tokenType){
    if (htparser->_curToken->_htTokenType == tokenType) {
        htparser->_curToken = HTLexerGetNextToken(htparser->_htlexer);
    }
    else {
        HTLogTokenError(
            htparser->_curToken->_value, 
            htparser->_curToken->_htTokenType
        );
        exit(1);
    }
}


HT_AST* HTParser_Parse(HT_PARSER* htparser){
    
}

HT_AST* HTParser_ParseStatement(HT_PARSER* htparser){
    
}

HT_AST* HTParser_ParseStatements(HT_PARSER* htparser){
    HT_AST* compound = HTAstInit(HT_AST_COMPOUND_ST);
    compound->_compoundStValue = calloc(1, sizeof(struct _astStruct*));

    HT_AST* _statement = HTParser_ParseStatement(htparser);
    compound->_compoundStValue[0] = _statement;

    while (htparser->_curToken->_htTokenType == HT_TOKEN_SEMICOLON) {
        
        HTParserEat(htparser, HT_TOKEN_SEMICOLON);

        HT_AST* _statement = HTParser_ParseStatement(htparser);
        compound->_compoundStSize += 1;

        compound->_compoundStValue = realloc(
            compound->_compoundStValue, 
            compound->_compoundStSize * sizeof(struct _astStruct*)
        );
        compound->_compoundStValue[compound->_compoundStSize - 1] = _statement;
    }

    return compound;
}

HT_AST* HTParser_ParseExpression(HT_PARSER* htparser){
    
}

HT_AST* HTParser_ParseFactor(HT_PARSER* htparser){
    
}

HT_AST* HTParser_ParseTerm(HT_PARSER* htparser){
    
}


HT_AST* HTParser_ParseFunctionCall(HT_PARSER* htparser){
    
}

HT_AST* HTParser_ParseVar(HT_PARSER* htparser){
    
}

HT_AST* HTParser_ParseString(HT_PARSER* htparser){
    
}



