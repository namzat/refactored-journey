#ifndef ROMAN_NUMERAL_H
#define ROMAN_NUMERAL_H

typedef struct {
    const char character[2];
    const int value;
} roman_numeral_t;

static const int MAX_NUMERAL_SIZE = 14;
static const int NULL_TERMINATOR_SIZE = 1;

static const roman_numeral_t ROMAN_NUMERAL_M = { "M", 1000};
static const roman_numeral_t ROMAN_NUMERAL_D = { "D", 500};
static const roman_numeral_t ROMAN_NUMERAL_C = { "C", 100};
static const roman_numeral_t ROMAN_NUMERAL_L = { "L", 50};
static const roman_numeral_t ROMAN_NUMERAL_X = { "X", 10};
static const roman_numeral_t ROMAN_NUMERAL_V = { "V", 5};
static const roman_numeral_t ROMAN_NUMERAL_I = { "I", 1};

const int integer_to_numeral(const int number, char *numeral);
const int numeral_to_integer(const char *numeral);

#endif /* ROMAN_NUMERAL_H */