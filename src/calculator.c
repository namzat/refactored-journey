#include <bsd/string.h>
#include <stdlib.h>
#include "calculator.h"

const char * add(const char *operand1, const char *operand2) {
    int operand1value = 0;
    int operand2value = 0;
    int total = 0;
    char *numeraltotal;

    if(strcmp(operand1, "I") == 0) {
        operand1value = 1;
    }
    else if (strcmp(operand1, "II") == 0) {
        operand1value = 2;
    }

    if(strcmp(operand2, "I") == 0) {
        operand2value = 1;
    }
    else if (strcmp(operand2, "II") == 0) {
        operand2value = 2;
    }

    total = operand1value + operand2value;
    if((numeraltotal = calloc(total, sizeof(char)))) {
        for(int i = 0; i < total; ++i) {
            strlcat(numeraltotal, "I", sizeof(numeraltotal));       
        }
    }

    return numeraltotal;
}