#ifndef ROMAN_NUMERAL_H
#define ROMAN_NUMERAL_H

static const int MAX_NUMERAL_SIZE = 14;
static const int NULL_TERMINATOR_SIZE = 1;

const int integer_to_numeral(const int number, char *numeral);
const int numeral_to_integer(const char *numeral);

#endif /* ROMAN_NUMERAL_H */