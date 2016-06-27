#include "roman_numeral.h"
#include <bsd/string.h>
#include <stdlib.h>
#include <stdio.h>
#include <regex.h>

#define MAX_COMPARE_ROMAN_NUMERAL_SIZE 2

typedef struct {
    const char character[MAX_COMPARE_ROMAN_NUMERAL_SIZE];
    const int value;
} roman_numeral_t;

static const roman_numeral_t ROMAN_NUMERAL_M = { "M", 1000};
static const roman_numeral_t ROMAN_NUMERAL_CM = { "CM", 900};
static const roman_numeral_t ROMAN_NUMERAL_D = { "D", 500};
static const roman_numeral_t ROMAN_NUMERAL_CD = { "CD", 400};
static const roman_numeral_t ROMAN_NUMERAL_C = { "C", 100};
static const roman_numeral_t ROMAN_NUMERAL_XC = { "XC", 90};
static const roman_numeral_t ROMAN_NUMERAL_L = { "L", 50};
static const roman_numeral_t ROMAN_NUMERAL_XL = { "XL", 40};
static const roman_numeral_t ROMAN_NUMERAL_X = { "X", 10};
static const roman_numeral_t ROMAN_NUMERAL_IX = { "IX", 9};
static const roman_numeral_t ROMAN_NUMERAL_V = { "V", 5};
static const roman_numeral_t ROMAN_NUMERAL_IV = { "IV", 4};
static const roman_numeral_t ROMAN_NUMERAL_I = { "I", 1};

static const int extract_roman_numeral(const int initial_value, roman_numeral_t conversion_numeral, char* resultant_numeral) {
    int remainder = initial_value;
    int multiplier = 0;

    if(NULL == resultant_numeral) return -1;

    multiplier = remainder / conversion_numeral.value;
    for(int i = 0; i < multiplier; ++i) {
        strlcat(resultant_numeral,conversion_numeral.character, sizeof(resultant_numeral));
        remainder -= conversion_numeral.value;
    }

    return remainder;
}

const int integer_to_numeral(const int number, char *numeral) {
    if(NULL == numeral) return -1;

    int remainder = 0;
    
    remainder = extract_roman_numeral(number, ROMAN_NUMERAL_M, numeral);

    remainder = extract_roman_numeral(remainder, ROMAN_NUMERAL_CM, numeral);
    remainder = extract_roman_numeral(remainder, ROMAN_NUMERAL_D, numeral);
    remainder = extract_roman_numeral(remainder, ROMAN_NUMERAL_CD, numeral);
    remainder = extract_roman_numeral(remainder, ROMAN_NUMERAL_C, numeral);
    remainder = extract_roman_numeral(remainder, ROMAN_NUMERAL_XC, numeral);
    remainder = extract_roman_numeral(remainder, ROMAN_NUMERAL_L, numeral);
    remainder = extract_roman_numeral(remainder, ROMAN_NUMERAL_XL, numeral);
    remainder = extract_roman_numeral(remainder, ROMAN_NUMERAL_X, numeral);
    remainder = extract_roman_numeral(remainder, ROMAN_NUMERAL_IX, numeral);
    remainder = extract_roman_numeral(remainder, ROMAN_NUMERAL_V, numeral);
    remainder = extract_roman_numeral(remainder, ROMAN_NUMERAL_IV, numeral);
    remainder = extract_roman_numeral(remainder, ROMAN_NUMERAL_I, numeral);

    return remainder;
}

static int numeral_has_invalid_characters(const char *numeral) {
    regex_t regex;
    int returnval = 0;
    
    /*
        Regex patterns used:
        [^IVXLCDM] - disallow characters that are not the roman numerals I,V,X,L,C,D,M
        I{4,}, V{2,}, X{4,}...etc. - disallow n or more characters in a row
        II[VXLCDM], V[XLCDM],...etc. - disallow larger numeral after smaller for non subtract cases
    */
    const char *pattern = "[^IVXLCDM]|I{4,}|V{2,}|X{4,}|L{2,}|C{4,}|D{2,}|M{4,}|II[VXLCDM]|V[XLCDM]|XX[LCDM]|L[CDM]|CC[DM]|D[M]";
    
    if (regcomp(&regex, pattern, REG_EXTENDED)) { // make sure regex compilation worked
        printf("regex failed");
        returnval = 1;
    }
    else if(regexec(&regex, numeral, 0, NULL, 0) == 0) { // look for a match
        returnval = 1;
    }

    regfree(&regex);

    return returnval;
}

static int sum_numeral_parts(int numeral_part_values[], int numeral_part_values_array_length) {
    int totalvalue = 0;
    int next_character_index = 0;
    int current_character_value = 0;
    int next_character_value = 0;

    for(int char_index = 0; char_index < numeral_part_values_array_length; ++char_index) 
    {
        next_character_index = char_index + 1;
        current_character_value = numeral_part_values[char_index];
        next_character_value = numeral_part_values[next_character_index];

        if((next_character_index < numeral_part_values_array_length) && (next_character_value > current_character_value))
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

const int numeral_to_integer(const char * numeral) {
    const int values_array_length = strlen(numeral);

    if(NULL == numeral) return -1;
    if(0 == values_array_length) return -1;
    if(numeral_has_invalid_characters(numeral)) return -1;
    
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

