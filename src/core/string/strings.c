
#include <stddef.h>
#include "../datatype.h"
#include "strings.h"
#include <stdlib.h>
String string_init(){
    return (String) {.data = NULL, .length = 0};
}

String string_create(const u8 *data, u64 length){
    if(data == NULL || length == 0){
        return string_init();
    }

    String s;

    s.data = malloc(length);
    if(s.data == NULL){
        return string_init();
    }

    s.length = length;

    return s;
}
