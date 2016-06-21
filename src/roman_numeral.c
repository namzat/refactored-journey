#include "roman_numeral.h"
#include <bsd/string.h>
#include <stdlib.h>
#include <stdio.h>

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
    const int numeral_size = strlen(numeral);
    int numeral_part_values[numeral_size];

    if(strstr(numeral, "IIII") != NULL) {
        return 0;
    }
    
    for(int i = 0; i < numeral_size; ++i)
    {
        switch(numeral[i]) {
            case 'M':
                numeral_part_values[i] = 1000;
                break;
            case 'D':
                numeral_part_values[i] = 500;
                break;
            case 'C':
                numeral_part_values[i] = 100;
                break;
            case 'L':
                numeral_part_values[i] = 50;
                break;
            case 'X':
                numeral_part_values[i] = 10;
                break;
            case 'V': 
                numeral_part_values[i] = 5;
                break;
            case 'I':
                numeral_part_values[i] = 1;
                break;
            default:
                numeral_part_values[i] = 0;
        }
    }

    int totalvalue = 0;
    for(int j = 0; j < numeral_size; ++j) {
        if((j + 1 < numeral_size) && (numeral_part_values[j+1] > numeral_part_values[j])) {
            totalvalue += numeral_part_values[j + 1] - numeral_part_values[j];
            j++;
        }
        else {
            totalvalue += numeral_part_values[j];
        }
    }

    return totalvalue;    
}