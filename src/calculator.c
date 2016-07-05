#include "calculator.h"
#include "roman_numeral.h"
#include "common.h"
#include <bsd/string.h>
#include <stdlib.h>
#include <stdio.h>

const int add(const char *operand1, const char *operand2, char *total) {
    if (NULL == total) return STATUS_FAIL;

    int operand1_arabic_value = 0;
    int operand2_arabic_value = 0;
    int arabic_total = 0;
    char roman_total[MAX_NUMERAL_SIZE] = {'\0'};

    operand1_arabic_value = roman_to_arabic(operand1);
    operand2_arabic_value = roman_to_arabic(operand2);
        
    arabic_total = operand1_arabic_value + operand2_arabic_value;

    int status = arabic_to_roman(arabic_total, roman_total);  

    strlcat(total, roman_total, sizeof(total));
    
    return status;
}