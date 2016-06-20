#include "roman_numeral.h"
#include <bsd/string.h>
#include <stdlib.h>

static const int MAX_NUMERAL_SIZE = 14;

const char * integer_to_numeral(int number) {
    char* numeral;
    
    if((numeral = calloc(MAX_NUMERAL_SIZE, sizeof(char)))) {
        for(int i = 0; i < number; ++i) {
            strlcat(numeral, "I", sizeof(numeral));       
        }
    }

    return numeral;
}

int numeral_to_integer(const char * numeral) {
    if(strncmp(numeral, "IV", MAX_NUMERAL_SIZE) == 0) {
        return 4;
    }
    else if(strncmp(numeral, "V", MAX_NUMERAL_SIZE) == 0) {
        return 5;
    }
    else if(strncmp(numeral, "I", MAX_NUMERAL_SIZE) == 0) {
            return 1;
    }
    else if (strncmp(numeral, "II", MAX_NUMERAL_SIZE) == 0) {
        return 2;
    }
    else
        return 0;       
}