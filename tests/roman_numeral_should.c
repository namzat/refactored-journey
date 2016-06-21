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

START_TEST(convert_XL_to_40) {
    ck_assert_int_eq(numeral_to_integer("XL"), 40);
} END_TEST

START_TEST(convert_C_to_100) {
    ck_assert_int_eq(numeral_to_integer("C"), 100);
} END_TEST

START_TEST(convert_XC_to_90) {
    ck_assert_int_eq(numeral_to_integer("XC"), 90);
} END_TEST

START_TEST(convert_D_to_500) {
    ck_assert_int_eq(numeral_to_integer("D"), 500);
} END_TEST

START_TEST(convert_CD_to_400) {
    ck_assert_int_eq(numeral_to_integer("CD"), 400);
} END_TEST

START_TEST(convert_M_to_1000) {
    ck_assert_int_eq(numeral_to_integer("M"), 1000);
} END_TEST

START_TEST(convert_CMXCIX_to_999) {
    ck_assert_int_eq(numeral_to_integer("CMXCIX"), 999);
} END_TEST

START_TEST(convert_XLIX_to_49) {
    ck_assert_int_eq(numeral_to_integer("XLIX"), 49);
} END_TEST

START_TEST(do_not_convert_IIII_return_0) {
    ck_assert_int_eq(numeral_to_integer("IIII"), 0);
} END_TEST

START_TEST(do_not_convert_VV_or_more_return_0) {
    ck_assert_int_eq(numeral_to_integer("VV"), 0);
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
    tcase_add_test(tc_core, convert_XL_to_40);
    tcase_add_test(tc_core, convert_C_to_100);
    tcase_add_test(tc_core, convert_XC_to_90);
    tcase_add_test(tc_core, convert_D_to_500);
    tcase_add_test(tc_core, convert_CD_to_400);
    tcase_add_test(tc_core, convert_M_to_1000);
    tcase_add_test(tc_core, convert_CMXCIX_to_999);
    tcase_add_test(tc_core, convert_XLIX_to_49);
    tcase_add_test(tc_core, do_not_convert_IIII_return_0);
    tcase_add_test(tc_core, do_not_convert_VV_or_more_return_0);

    suite_add_tcase(s, tc_core);

    return s;
}
