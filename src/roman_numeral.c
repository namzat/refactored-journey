#include "roman_numeral.h"
#include "common.h"
#include <bsd/string.h>
#include <stdlib.h>
#include <stdio.h>
#include <regex.h>
#include <stdbool.h>

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

    if(NULL == resultant_numeral) return STATUS_FAIL;

    multiplier = remainder / conversion_numeral.value;
    for(int i = 0; i < multiplier; ++i) {
        strlcat(resultant_numeral,conversion_numeral.character, sizeof(resultant_numeral));
        remainder -= conversion_numeral.value;
    }

    return remainder;
}

const int arabic_to_roman(const int number, char *roman) {
    if(NULL == roman) return STATUS_FAIL;
    
    int remainder = 0;
    
    remainder = extract_roman_numeral(number, ROMAN_NUMERAL_M, roman);

    remainder = extract_roman_numeral(remainder, ROMAN_NUMERAL_CM, roman);
    remainder = extract_roman_numeral(remainder, ROMAN_NUMERAL_D, roman);
    remainder = extract_roman_numeral(remainder, ROMAN_NUMERAL_CD, roman);
    remainder = extract_roman_numeral(remainder, ROMAN_NUMERAL_C, roman);
    remainder = extract_roman_numeral(remainder, ROMAN_NUMERAL_XC, roman);
    remainder = extract_roman_numeral(remainder, ROMAN_NUMERAL_L, roman);
    remainder = extract_roman_numeral(remainder, ROMAN_NUMERAL_XL, roman);
    remainder = extract_roman_numeral(remainder, ROMAN_NUMERAL_X, roman);
    remainder = extract_roman_numeral(remainder, ROMAN_NUMERAL_IX, roman);
    remainder = extract_roman_numeral(remainder, ROMAN_NUMERAL_V, roman);
    remainder = extract_roman_numeral(remainder, ROMAN_NUMERAL_IV, roman);
    remainder = extract_roman_numeral(remainder, ROMAN_NUMERAL_I, roman);

    return STATUS_SUCCESS;
}

static bool roman_numeral_is_invalid(const char *numeral) {
    regex_t regex;
    bool status = false;
    
    /*
        Regex patterns used:
        [^IVXLCDM] - disallow characters that are not the roman numerals I,V,X,L,C,D,M
        I{4,}, V{2,}, X{4,}...etc. - disallow n or more characters in a row
        II[VXLCDM], V[XLCDM],...etc. - disallow larger numeral after smaller for non subtract cases
    */
    const char *pattern = "[^IVXLCDM]|I{4,}|V{2,}|X{4,}|L{2,}|C{4,}|D{2,}|M{4,}|II[VXLCDM]|V[XLCDM]|XX[LCDM]|L[CDM]|CC[DM]|D[M]";
    
    if (regcomp(&regex, pattern, REG_EXTENDED)) { // make sure regex compilation worked
        printf("regex failed");
        status = true;
    }
    else if(regexec(&regex, numeral, 0, NULL, 0) == 0) { // look for a match
        status = true;
    }

    regfree(&regex);

    return status;
}

static int sum_numeral_parts(int roman_numeral_part_values[], int roman_numeral_part_values_array_length) {
    int totalvalue = 0;
    int next_character_index = 0;
    int current_character_value = 0;
    int next_character_value = 0;

    for(int char_index = 0; char_index < roman_numeral_part_values_array_length; ++char_index) 
    {
        next_character_index = char_index + 1;
        current_character_value = roman_numeral_part_values[char_index];
        next_character_value = roman_numeral_part_values[next_character_index];

        if((next_character_index < roman_numeral_part_values_array_length) && (next_character_value > current_character_value))
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

const int roman_to_arabic(const char * roman) {
    const int values_array_length = strlen(roman);

    if(NULL == roman) return 0;
    if(0 == values_array_length) return 0;
    if(roman_numeral_is_invalid(roman)) return 0;
    
    int roman_numeral_part_values[values_array_length];
    int totalValue = 0;

    for(int i = 0; i < values_array_length; ++i) {
        switch(roman[i]) {
            case 'M':
                roman_numeral_part_values[i] = ROMAN_NUMERAL_M.value;
                break;
            case 'D':
                roman_numeral_part_values[i] = ROMAN_NUMERAL_D.value;
                break;
            case 'C':
                roman_numeral_part_values[i] = ROMAN_NUMERAL_C.value;
                break;
            case 'L':
                roman_numeral_part_values[i] = ROMAN_NUMERAL_L.value;
                break;
            case 'X':
                roman_numeral_part_values[i] = ROMAN_NUMERAL_X.value;
                break;
            case 'V': 
                roman_numeral_part_values[i] = ROMAN_NUMERAL_V.value;
                break;
            case 'I':
                roman_numeral_part_values[i] = ROMAN_NUMERAL_I.value;
                break;
            default:
                return STATUS_FAIL;
        }
    }

    totalValue = sum_numeral_parts(roman_numeral_part_values, values_array_length);

    return totalValue;
}

