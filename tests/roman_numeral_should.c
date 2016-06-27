#include <stdio.h>
#include <stdlib.h>
#include "roman_numeral_should.h"
#include "../src/roman_numeral.h"

void assert_int_to_roman_conversion(const int integer, const char *expected_numeral) {
    char *result = calloc(strlen(expected_numeral) ,sizeof(char));
    int status = integer_to_numeral(integer, result);
    ck_assert_int_eq(0, status);
    ck_assert_str_eq(expected_numeral, result);
    free(result);
}

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

START_TEST(convert_1000_to_M) {
    assert_int_to_roman_conversion(1000, "M");
} END_TEST

START_TEST(convert_900_to_CM) {
    assert_int_to_roman_conversion(900, "CM");
} END_TEST

START_TEST(convert_500_to_D) {
    assert_int_to_roman_conversion(500, "D");
} END_TEST

START_TEST(convert_400_to_CD) {
    assert_int_to_roman_conversion(400, "CD");
} END_TEST

START_TEST(convert_100_to_C) {
    assert_int_to_roman_conversion(100, "C");
} END_TEST

START_TEST(convert_90_to_XC) {
    assert_int_to_roman_conversion(90, "XC");
} END_TEST

START_TEST(convert_50_to_L) {
    assert_int_to_roman_conversion(50, "L");
} END_TEST

START_TEST(convert_40_to_XL) {
    assert_int_to_roman_conversion(40, "XL");
} END_TEST

START_TEST(convert_10_to_X) {
    assert_int_to_roman_conversion(10, "X");
} END_TEST

START_TEST(convert_9_to_IX) {
    assert_int_to_roman_conversion(9, "IX");
} END_TEST

START_TEST(convert_5_to_V) {
    assert_int_to_roman_conversion(5, "V");
} END_TEST

START_TEST(convert_4_to_IV) {
    assert_int_to_roman_conversion(4, "IV");
} END_TEST

START_TEST(convert_1_to_I) {
    assert_int_to_roman_conversion(1, "I");
} END_TEST

START_TEST(reject_invalid_character_patterns) {
    ck_assert_int_eq(-1,numeral_to_integer(""));
    ck_assert_int_eq(-1,numeral_to_integer("MMMM"));
    ck_assert_int_eq(-1,numeral_to_integer("IIII"));
    ck_assert_int_eq(-1,numeral_to_integer("VV"));
    ck_assert_int_eq(-1,numeral_to_integer("XXXX"));
    ck_assert_int_eq(-1,numeral_to_integer("LL"));
    ck_assert_int_eq(-1,numeral_to_integer("CCCC"));
    ck_assert_int_eq(-1,numeral_to_integer("DD"));
    ck_assert_int_eq(-1,numeral_to_integer("MMMM"));
    ck_assert_int_eq(-1,numeral_to_integer("1"));
    ck_assert_int_eq(-1,numeral_to_integer("a"));
    ck_assert_int_eq(-1,numeral_to_integer("A"));
    ck_assert_int_eq(-1,numeral_to_integer("IIIV"));
    ck_assert_int_eq(-1,numeral_to_integer("VX"));
    ck_assert_int_eq(-1,numeral_to_integer("VL"));
    ck_assert_int_eq(-1,numeral_to_integer("VC"));
    ck_assert_int_eq(-1,numeral_to_integer("VM"));
    ck_assert_int_eq(-1,numeral_to_integer("XXL"));
    ck_assert_int_eq(-1,numeral_to_integer("XXC"));
    ck_assert_int_eq(-1,numeral_to_integer("XXD"));
    ck_assert_int_eq(-1,numeral_to_integer("XXM"));
    ck_assert_int_eq(-1,numeral_to_integer("LC"));
    ck_assert_int_eq(-1,numeral_to_integer("LD"));
    ck_assert_int_eq(-1,numeral_to_integer("LM"));
    ck_assert_int_eq(-1,numeral_to_integer("CCD"));
    ck_assert_int_eq(-1,numeral_to_integer("CCM"));
    ck_assert_int_eq(-1,numeral_to_integer("DM"));
} END_TEST


Suite * roman_numeral_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("roman_numeral");

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
    tcase_add_test(tc_core, reject_invalid_character_patterns);
    tcase_add_test(tc_core, convert_1000_to_M);
    tcase_add_test(tc_core, convert_900_to_CM);
    tcase_add_test(tc_core, convert_500_to_D);
    tcase_add_test(tc_core, convert_400_to_CD);
    tcase_add_test(tc_core, convert_100_to_C);
    tcase_add_test(tc_core, convert_90_to_XC);
    tcase_add_test(tc_core, convert_50_to_L);
    tcase_add_test(tc_core, convert_40_to_XL);
    tcase_add_test(tc_core, convert_10_to_X);
    tcase_add_test(tc_core, convert_9_to_IX);
    tcase_add_test(tc_core, convert_5_to_V);
    tcase_add_test(tc_core, convert_4_to_IV);
    tcase_add_test(tc_core, convert_1_to_I);
    

    suite_add_tcase(s, tc_core);

    return s;
}
