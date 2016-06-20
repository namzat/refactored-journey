#include "calculator_should.h"
#include "roman_numeral_should.h"

int main(void) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = calculator_suite();

    sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    s = roman_numeral_suite();
    sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    number_failed += srunner_ntests_failed(sr);
    srunner_free(sr);

    return(number_failed == 0) ? 0 : 1;
}
