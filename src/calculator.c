#include "calculator.h"
#include "roman_numeral.h"
#include "common.h"
#include <bsd/string.h>
#include <stdlib.h>
#include <stdio.h>

const unsigned int add(char *sum,const char *augend, const char *addend) {
    if ((NULL == augend) || (NULL == addend) || (NULL == sum)) return EXIT_FAILURE;

    int augend_arabic_value = 0;
    int addend_arabic_value = 0;
    int arabic_sum = 0;

    augend_arabic_value = roman_to_arabic(augend);
    addend_arabic_value = roman_to_arabic(addend);
        
    arabic_sum = augend_arabic_value + addend_arabic_value;

    int status = arabic_to_roman(sum, arabic_sum); 
    
    return status;
}

const unsigned int subtract(char *difference, const char *minuend, const char *subtrahend) {
    if((NULL == minuend) || (NULL == subtrahend) || (NULL == difference)) return EXIT_FAILURE;

    int minuend_arabic_value = 0;
    int subtrahend_arabic_value = 0;
    int arabic_difference = 0;

    minuend_arabic_value = roman_to_arabic(minuend);
    subtrahend_arabic_value = roman_to_arabic(subtrahend);

    if(minuend <= subtrahend) return EXIT_FAILURE;

    arabic_difference = minuend_arabic_value - subtrahend_arabic_value;

    int status = arabic_to_roman(difference, arabic_difference);
    
    return status;
}