#ifndef HT_PARSER_H
#define HT_PARSER_H

#include "Lexer.h"
#include "Ast.h"

typedef struct _parserStruct {

    HT_Lexer* _htlexer;
    HT_Token* _curToken;

} HT_PARSER;

HT_PARSER* HTParserInit(HT_Lexer* htlexer);
void HTParserEat(HT_PARSER* htparser, int tokenType);

HT_AST* HTParser_Parse(HT_PARSER* htparser);
HT_AST* HTParser_ParseStatement(HT_PARSER* htparser);
HT_AST* HTParser_ParseStatements(HT_PARSER* htparser);
HT_AST* HTParser_ParseExpression(HT_PARSER* htparser);
HT_AST* HTParser_ParseFactor(HT_PARSER* htparser);
HT_AST* HTParser_ParseTerm(HT_PARSER* htparser);

HT_AST* HTParser_ParseFunctionCall(HT_PARSER* htparser);
HT_AST* HTParser_ParseVar(HT_PARSER* htparser);
HT_AST* HTParser_ParseString(HT_PARSER* htparser);


#endif