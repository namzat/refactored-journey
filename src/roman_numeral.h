#ifndef ROMAN_NUMERAL_H
#define ROMAN_NUMERAL_H

#define MAX_NUMERAL_SIZE 14
#define NULL_TERMINATOR_SIZE 1
#define STATUS_FAIL -1
#define STATUS_SUCCESS 0

const int integer_to_numeral(const int number, char *numeral);
const int numeral_to_integer(const char *numeral);

#endif /* ROMAN_NUMERAL_H */