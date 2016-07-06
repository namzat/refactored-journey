#include "calculator.h"
#include "roman_numeral.h"
#include "common.h"
#include <bsd/string.h>
#include <stdlib.h>
#include <stdio.h>

const unsigned int add(char *total,const char *operand1, const char *operand2) {
    if ((NULL == operand1) || (NULL == operand2) || (NULL == total)) return EXIT_FAILURE;

    int operand1_arabic_value = 0;
    int operand2_arabic_value = 0;
    int arabic_total = 0;
    char roman_total[MAX_ROMAN_NUMERAL_STRING_SIZE] = {'\0'};

    operand1_arabic_value = roman_to_arabic(operand1);
    operand2_arabic_value = roman_to_arabic(operand2);
        
    arabic_total = operand1_arabic_value + operand2_arabic_value;

    int status = arabic_to_roman(roman_total, arabic_total); 

    strlcpy(total, roman_total, MAX_ROMAN_NUMERAL_STRING_SIZE);
    
    return status;
}

const unsigned int subtract(char *difference, const char *minuend, const char *subtrahend) {
    if((NULL == minuend)) return EXIT_FAILURE;

    int minuend_arabic_value = 0;
    int subtrahend_arabic_value = 0;
    int arabic_difference = 0;

    minuend_arabic_value = roman_to_arabic(minuend);
    subtrahend_arabic_value = roman_to_arabic(subtrahend);

    arabic_difference = minuend_arabic_value - subtrahend_arabic_value;

    int status = arabic_to_roman(difference, arabic_difference);
    
    return status;
}