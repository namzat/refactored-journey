#include "calculator.h"
#include "roman_numeral.h"
#include <bsd/string.h>
#include <stdlib.h>
#include <stdio.h>

const char * add(const char *operand1, const char *operand2) {
    int operand1value = 0;
    int operand2value = 0;
    int total = 0;
    char *numeraltotal = calloc(MAX_NUMERAL_SIZE + NULL_TERMINATOR_SIZE, sizeof(char));
    char *returnvalue = 0;

    operand1value = numeral_to_integer(operand1);
    operand2value = numeral_to_integer(operand2);

    total = operand1value + operand2value;

    int status = integer_to_numeral(total, numeraltotal);  
    if(status == 0) {
        
        returnvalue = strdup(numeraltotal);
        free(numeraltotal);
        return returnvalue;
    }
    else {
        return "An error occured";
    }     
}