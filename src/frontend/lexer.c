#include "../core/datatype.h"
#include "lexer.h"

void scannerInit(const u8 *src){
    Scanner scanner;

    scanner.start = src;
    scanner.position = src;
    scanner.line = 1;
    scanner.endline = false;
}

