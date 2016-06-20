#include <stdio.h>
#include "check_roman_numeral.h"
#include "../src/roman_numeral.h"

START_TEST(I_converts_to_1) {
    ck_assert_int_eq(numeral_to_integer("I"), 1);
} END_TEST

Suite * roman_numeral_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("roman numeral");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, I_converts_to_1);

    suite_add_tcase(s, tc_core);

    return s;
}