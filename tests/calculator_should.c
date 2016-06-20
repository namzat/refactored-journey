#include <stdio.h>
#include "calculator_should.h"
#include "../src/calculator.h"

START_TEST(calculate_I_plus_I_as_II) {
    ck_assert_str_eq(add("I", "I"), "II");
} END_TEST

START_TEST(calculate_I_plus_II_as_III) {
    ck_assert_str_eq(add("I", "II"), "III");
} END_TEST

Suite * calculator_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("calculator");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, calculate_I_plus_I_as_II);
    tcase_add_test(tc_core, calculate_I_plus_II_as_III);

    suite_add_tcase(s, tc_core);

    return s;
}
