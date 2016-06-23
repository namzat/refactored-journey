#ifndef ROMAN_NUMERAL_H
#define ROMAN_NUMERAL_H

static const int MAX_NUMERAL_SIZE = 14;
static const int NULL_TERMINATOR_SIZE = 1;
static const int ROMAN_NUMERAL_I_VALUE = 1;
static const int ROMAN_NUMERAL_M_VALUE = 1000;
static const int ROMAN_NUMERAL_D_VALUE = 500;

const int integer_to_numeral(const int number, char *numeral);
const int numeral_to_integer(const char *numeral);

#endif /* ROMAN_NUMERAL_H */