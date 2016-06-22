#include "roman_numeral.h"
#include <bsd/string.h>
#include <stdlib.h>
#include <stdio.h>
#include <regex.h>

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

static int numeral_has_invalid_characters(const char *numeral) {
    regex_t start_state;
    const char *pattern = "[^IVXLCDM]|I{4,}|V{2,}|X{4,}|L{2,}|C{4,}|D{2,}|M{4,}";
    if (regcomp(&start_state, pattern, REG_EXTENDED)) {
        printf("regex failed");
        return 1;
    }

    if(regexec(&start_state, numeral, 0, NULL, 0) == 0) {
        return 1;
    }

    return 0;
}

static int sum_numeral_parts(int numeral_part_values[], int array_length) {
    int totalvalue = 0;
    int next_character_index = 0;
    int current_character_value = 0;
    int next_character_value = 0;

    for(int char_index = 0; char_index < array_length; ++char_index) 
    {
        next_character_index = char_index + 1;
        current_character_value = numeral_part_values[char_index];
        next_character_value = numeral_part_values[next_character_index];

        if((next_character_index < array_length) && (next_character_value > current_character_value))
        {
            totalvalue += next_character_value - current_character_value;
            char_index++;
        }
        else
        {
            totalvalue += current_character_value;
        }
    }

    return totalvalue; 
}

int numeral_to_integer(const char * numeral) {
    if(numeral == NULL) return -1;
    if(strlen(numeral) == 0) return -1;
    if(numeral_has_invalid_characters(numeral)) return -1;
    
    const int values_array_length = strlen(numeral);
    int numeral_part_values[values_array_length];
    int totalValue = 0;

    for(int i = 0; i < values_array_length; ++i) {
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
                return -1;
        }
    }

    totalValue = sum_numeral_parts(numeral_part_values, values_array_length);

    return totalValue;
}

