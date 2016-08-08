#include "roman_numeral.h"
#include "common.h"
#include <bsd/string.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <regex.h>
#include <stdbool.h>

#define MAX_COMPARE_ROMAN_NUMERAL_SIZE 2

typedef struct { 
    const char character[MAX_COMPARE_ROMAN_NUMERAL_SIZE];
    const unsigned int value;
} roman_numeral_t;

static const roman_numeral_t roman_numeral_M  =  { "M" , 1000 };
static const roman_numeral_t roman_numeral_CM =  { "CM", 900 };
static const roman_numeral_t roman_numeral_D  =  { "D" , 500 };
static const roman_numeral_t roman_numeral_CD =  { "CD", 400 };
static const roman_numeral_t roman_numeral_C  =  { "C" , 100 };
static const roman_numeral_t roman_numeral_XC =  { "XC", 90 };
static const roman_numeral_t roman_numeral_L  =  { "L" , 50 };
static const roman_numeral_t roman_numeral_XL =  { "XL", 40 };
static const roman_numeral_t roman_numeral_X  =  { "X" , 10 };
static const roman_numeral_t roman_numeral_IX =  { "IX", 9 };
static const roman_numeral_t roman_numeral_V  =  { "V" , 5 };
static const roman_numeral_t roman_numeral_IV =  { "IV", 4 };
static const roman_numeral_t roman_numeral_I  =  { "I" , 1 };

static const unsigned int concat_roman_numeral(char* resultant_numeral_out, const unsigned int initial_value, roman_numeral_t numeral_to_extract) {
    unsigned int remainder = initial_value;
    int multiplier = 0;

    multiplier = remainder / numeral_to_extract.value;
    for(int i = 0; i < multiplier; ++i) {
        strlcat(resultant_numeral_out ,numeral_to_extract.character, MAX_ROMAN_NUMERAL_STRING_SIZE);
        remainder -= numeral_to_extract.value;
    }

    return remainder;
}

const int arabic_to_roman(char *roman_out, const unsigned int number) {
    if(NULL == roman_out) return EXIT_FAILURE;
    
    int remainder = 0;
    
    remainder = concat_roman_numeral(roman_out, number,    roman_numeral_M);
    remainder = concat_roman_numeral(roman_out, remainder, roman_numeral_CM);
    remainder = concat_roman_numeral(roman_out, remainder, roman_numeral_D);
    remainder = concat_roman_numeral(roman_out, remainder, roman_numeral_CD);
    remainder = concat_roman_numeral(roman_out, remainder, roman_numeral_C);
    remainder = concat_roman_numeral(roman_out, remainder, roman_numeral_XC);
    remainder = concat_roman_numeral(roman_out, remainder, roman_numeral_L);
    remainder = concat_roman_numeral(roman_out, remainder, roman_numeral_XL);
    remainder = concat_roman_numeral(roman_out, remainder, roman_numeral_X);
    remainder = concat_roman_numeral(roman_out, remainder, roman_numeral_IX);
    remainder = concat_roman_numeral(roman_out, remainder, roman_numeral_V);
    remainder = concat_roman_numeral(roman_out, remainder, roman_numeral_IV);
    remainder = concat_roman_numeral(roman_out, remainder, roman_numeral_I);

    return remainder;
}

static bool roman_numeral_is_invalid(const char *numeral) {
    regex_t regex;
    bool status = false;
    
    /*
        Regex patterns used:
        [^IVXLCDM] - disallow characters that are not the roman numerals I,V,X,L,C,D,M
        I{4,}, V{2,}, X{4,}...etc. - disallow n or more characters in a row
        II[VXLCDM], V[XLCDM],...etc. - disallow larger numeral after smaller for non subtract cases
        I[LCDM], X[DM] - disallow I before LCDM and X before DM
    */
    const char *pattern = "[^IVXLCDM]|I{4,}|V{2,}|X{4,}|L{2,}|C{4,}|D{2,}|M{4,}|II[VXLCDM]|V[XLCDM]|XX[LCDM]|L[CDM]|CC[DM]|D[M]|I[LCDM]|X[DM]";
    
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

static int sum_numeral_parts(unsigned int roman_numeral_part_values[], unsigned int roman_numeral_part_values_array_length) {
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

const unsigned int roman_to_arabic(const char * roman) {
    if(NULL == roman) return 0;
    if(roman_numeral_is_invalid(roman)) return 0;

    const unsigned int values_array_length = strnlen(roman, MAX_ROMAN_NUMERAL_STRING_SIZE);
    if((MAX_ROMAN_NUMERAL_STRING_SIZE) == values_array_length) return 0;

    unsigned int roman_numeral_part_values[values_array_length];
    unsigned int totalValue = 0;

    for(int i = 0; i < values_array_length; ++i) {
        switch(roman[i]) {
            case 'M':
                roman_numeral_part_values[i] = roman_numeral_M.value;
                break;
            case 'D':
                roman_numeral_part_values[i] = roman_numeral_D.value;
                break;
            case 'C':
                roman_numeral_part_values[i] = roman_numeral_C.value;
                break;
            case 'L':
                roman_numeral_part_values[i] = roman_numeral_L.value;
                break;
            case 'X':
                roman_numeral_part_values[i] = roman_numeral_X.value;
                break;
            case 'V': 
                roman_numeral_part_values[i] = roman_numeral_V.value;
                break;
            case 'I':
                roman_numeral_part_values[i] = roman_numeral_I.value;
                break;
            default:
                return 0;
        }
    }

    totalValue = sum_numeral_parts(roman_numeral_part_values, values_array_length);

    return totalValue;
}

