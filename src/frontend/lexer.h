#ifndef lexer_h
#define lexer_h
#include "token.h"

typedef struct{
    const char* start;
    const char* current;
    int line;
} Scanner;

Scanner scanner;

typedef struct{
    
 TokenType type;
 const char* start;
 size_t length;
 size_t line;
} Token;


typedef struct{

}
#endif
