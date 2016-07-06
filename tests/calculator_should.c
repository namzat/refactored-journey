#include "../src/common.h"
#include "../src/calculator.h"
#include <stdio.h>
#include <stdlib.h>
#include "calculator_should.h"


START_TEST(calculate_I_plus_I_as_II) {
    char roman_total[MAX_ROMAN_NUMERAL_STRING_SIZE] = {'\0'};
    int status = add(roman_total, "I", "I");
    ck_assert_int_eq(EXIT_SUCCESS, status);
    ck_assert_str_eq("II", roman_total);
} END_TEST

START_TEST(calculate_I_plus_II_as_III) {
    char roman_total[MAX_ROMAN_NUMERAL_STRING_SIZE] = {'\0'};
    int status = add(roman_total, "I", "II");
    ck_assert_int_eq(EXIT_SUCCESS, status);
    ck_assert_str_eq("III", roman_total);
} END_TEST

START_TEST(return_status_error_if_passed_null_value) {
    char *null_argument = 0;
    char roman_total[MAX_ROMAN_NUMERAL_STRING_SIZE];
    ck_assert_int_eq(EXIT_FAILURE, add(roman_total, null_argument, "I"));
    ck_assert_int_eq(EXIT_FAILURE, add(roman_total, "I", null_argument));
    ck_assert_int_eq(EXIT_FAILURE, add(null_argument, "I", "I"));
} END_TEST

START_TEST(calculate_V_minus_I_as_IV) {
    char roman_total[MAX_ROMAN_NUMERAL_STRING_SIZE] = {'0'};
    ck_assert_int_eq(EXIT_SUCCESS, subtract(roman_total, "V", "I"));
    ck_assert_str_eq("IV", roman_total);
} END_TEST

START_TEST(calculate_X_minus_II_as_VIII) {
    char roman_total[MAX_ROMAN_NUMERAL_STRING_SIZE] = {'0'};
    ck_assert_int_eq(EXIT_SUCCESS, subtract(roman_total, "X", "II"));
    ck_assert_str_eq("VIII", roman_total);
} END_TEST

Suite * calculator_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("calculator");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, calculate_I_plus_I_as_II);
    tcase_add_test(tc_core, calculate_I_plus_II_as_III);
    tcase_add_test(tc_core, return_status_error_if_passed_null_value);
    tcase_add_test(tc_core, calculate_V_minus_I_as_IV);
    tcase_add_test(tc_core, calculate_X_minus_II_as_VIII);

    suite_add_tcase(s, tc_core);

    return s;
}
