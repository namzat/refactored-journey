#include <stdio.h>
#include "roman_numeral_should.h"
#include "../src/roman_numeral.h"

START_TEST(convert_I_to_1) {
    ck_assert_int_eq(numeral_to_integer("I"), 1);
} END_TEST

START_TEST(convert_II_to_2) {
    ck_assert_int_eq(numeral_to_integer("II"), 2);
} END_TEST

START_TEST(convert_V_to_5) {
    ck_assert_int_eq(numeral_to_integer("V"), 5);
} END_TEST

START_TEST(convert_IV_to_4) {
    ck_assert_int_eq(numeral_to_integer("IV"), 4);
} END_TEST

START_TEST(convert_IX_to_9) {
    ck_assert_int_eq(numeral_to_integer("IX"), 9);
} END_TEST

START_TEST(convert_X_to_10) {
    ck_assert_int_eq(numeral_to_integer("X"), 10);
} END_TEST

START_TEST(convert_L_to_50) {
    ck_assert_int_eq(numeral_to_integer("L"), 50);
} END_TEST


Suite * roman_numeral_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("roman numeral");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, convert_I_to_1);
    tcase_add_test(tc_core, convert_II_to_2);
    tcase_add_test(tc_core, convert_V_to_5);
    tcase_add_test(tc_core, convert_IV_to_4);
    tcase_add_test(tc_core, convert_IX_to_9);
    tcase_add_test(tc_core, convert_X_to_10);
    tcase_add_test(tc_core, convert_L_to_50);

    suite_add_tcase(s, tc_core);

    return s;
}
