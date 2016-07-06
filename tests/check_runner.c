#include "calculator_should.h"
#include "roman_numeral_should.h"
#include <stdlib.h>

int main(void) {
    int number_failed = 0;
    Suite *calc_suite;
    Suite *roman_suite;
    SRunner *sr;

    calc_suite = calculator_suite();
    roman_suite = roman_numeral_suite();
    sr = srunner_create(calc_suite);
    srunner_add_suite(sr,roman_suite);
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return(number_failed == 0) ? 0 : 1;
}
