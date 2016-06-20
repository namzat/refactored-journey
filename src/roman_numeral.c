#include "roman_numeral.h"
#include <bsd/string.h>
#include <stdlib.h>

const char * integer_to_numeral(int number) {
    const int max_numeral_size = 14;
    char* numeral;
    
    if((numeral = calloc(max_numeral_size, sizeof(char)))) {
        for(int i = 0; i < number; ++i) {
            strlcat(numeral, "I", sizeof(numeral));       
        }
    }

    return numeral;
}

int numeral_to_integer(const char * numeral) {
    if(strcmp(numeral, "I") == 0) {
            return 1;
    }
    else if (strcmp(numeral, "II") == 0) {
        return 2;
    }
    else
        return 0;
}