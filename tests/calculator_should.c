#include "../src/common.h"
#include "../src/calculator.h"
#include <stdio.h>
#include "calculator_should.h"


START_TEST(calculate_I_plus_I_as_II) {
    char roman_total[MAX_NUMERAL_SIZE] = {'\0'};
    int status = add("I", "I", roman_total);
    ck_assert_int_eq(STATUS_SUCCESS, status);
    ck_assert_str_eq("II", roman_total);
} END_TEST

START_TEST(calculate_I_plus_II_as_III) {
    char roman_total[MAX_NUMERAL_SIZE] = {'\0'};
    int status = add("I", "II", roman_total);
    ck_assert_int_eq(STATUS_SUCCESS, status);
    ck_assert_str_eq("III", roman_total);
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
