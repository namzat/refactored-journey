#include <bsd/string.h>
#include <stdlib.h>
#include "calculator.h"
#include "roman_numeral.h"

const char * add(const char *operand1, const char *operand2) {
    int operand1value = 0;
    int operand2value = 0;
    int total = 0;
    const char *numeraltotal;

    operand1value = numeral_to_integer(operand1);
    operand2value = numeral_to_integer(operand2);

    total = operand1value + operand2value;

    numeraltotal = integer_to_numeral(total);  

    return numeraltotal;
}