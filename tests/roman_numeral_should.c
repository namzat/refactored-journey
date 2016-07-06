#include "../src/common.h"
#include "../src/roman_numeral.h"
#include "roman_numeral_should.h"
#include <stdio.h>
#include <stdlib.h>

static void assert_arabic_to_roman_conversion(const int arabic, const char *expected_numeral) {
    char result[MAX_ROMAN_NUMERAL_STRING_SIZE] = {'\0'};
    int status = arabic_to_roman(result, arabic);
    ck_assert_int_eq(EXIT_SUCCESS, status);
    ck_assert_str_eq(expected_numeral, result);
}

START_TEST(convert_I_to_1) {
    ck_assert_int_eq(roman_to_arabic("I"), 1);
} END_TEST

START_TEST(convert_II_to_2) {
    ck_assert_int_eq(roman_to_arabic("II"), 2);
} END_TEST

START_TEST(convert_III_to_3) {
    ck_assert_int_eq(roman_to_arabic("III"), 3);
} END_TEST

START_TEST(convert_V_to_5) {
    ck_assert_int_eq(roman_to_arabic("V"), 5);
} END_TEST

START_TEST(convert_IV_to_4) {
    ck_assert_int_eq(roman_to_arabic("IV"), 4);
} END_TEST

START_TEST(convert_IX_to_9) {
    ck_assert_int_eq(roman_to_arabic("IX"), 9);
} END_TEST

START_TEST(convert_X_to_10) {
    ck_assert_int_eq(roman_to_arabic("X"), 10);
} END_TEST

START_TEST(convert_XX_to_20) {
    ck_assert_int_eq(roman_to_arabic("XX"), 20);
} END_TEST

START_TEST(convert_XXX_to_30) {
    ck_assert_int_eq(roman_to_arabic("XXX"), 30);
} END_TEST

START_TEST(convert_L_to_50) {
    ck_assert_int_eq(roman_to_arabic("L"), 50);
} END_TEST

START_TEST(convert_XL_to_40) {
    ck_assert_int_eq(roman_to_arabic("XL"), 40);
} END_TEST

START_TEST(convert_C_to_100) {
    ck_assert_int_eq(roman_to_arabic("C"), 100);
} END_TEST

START_TEST(convert_CC_to_200) {
    ck_assert_int_eq(roman_to_arabic("CC"), 200);
} END_TEST

START_TEST(convert_CCC_to_300) {
    ck_assert_int_eq(roman_to_arabic("CCC"), 300);
} END_TEST

START_TEST(convert_XC_to_90) {
    ck_assert_int_eq(roman_to_arabic("XC"), 90);
} END_TEST

START_TEST(convert_D_to_500) {
    ck_assert_int_eq(roman_to_arabic("D"), 500);
} END_TEST

START_TEST(convert_CD_to_400) {
    ck_assert_int_eq(roman_to_arabic("CD"), 400);
} END_TEST

START_TEST(convert_M_to_1000) {
    ck_assert_int_eq(roman_to_arabic("M"), 1000);
} END_TEST

START_TEST(convert_MM_to_2000) {
    ck_assert_int_eq(roman_to_arabic("MM"), 2000);
} END_TEST

START_TEST(convert_MMM_to_3000) {
    ck_assert_int_eq(roman_to_arabic("MMM"), 3000);
} END_TEST

START_TEST(convert_CMXCIX_to_999) {
    ck_assert_int_eq(roman_to_arabic("CMXCIX"), 999);
} END_TEST

START_TEST(convert_XLIX_to_49) {
    ck_assert_int_eq(roman_to_arabic("XLIX"), 49);
} END_TEST

START_TEST(handle_longest_roman_value_MMMDCCCLXXXVIII_to_3888) {
    ck_assert_int_eq(roman_to_arabic("MMMDCCCLXXXVIII"), 3888);
} END_TEST

START_TEST(convert_3000_to_MMM) {
    assert_arabic_to_roman_conversion(3000, "MMM");
} END_TEST

START_TEST(convert_2000_to_MM) {
    assert_arabic_to_roman_conversion(2000, "MM");
} END_TEST

START_TEST(convert_1000_to_M) {
    assert_arabic_to_roman_conversion(1000, "M");
} END_TEST

START_TEST(convert_900_to_CM) {
    assert_arabic_to_roman_conversion(900, "CM");
} END_TEST

START_TEST(convert_500_to_D) {
    assert_arabic_to_roman_conversion(500, "D");
} END_TEST

START_TEST(convert_400_to_CD) {
    assert_arabic_to_roman_conversion(400, "CD");
} END_TEST

START_TEST(convert_300_to_CCC) {
    assert_arabic_to_roman_conversion(300, "CCC");
} END_TEST

START_TEST(convert_200_to_CC) {
    assert_arabic_to_roman_conversion(200, "CC");
} END_TEST

START_TEST(convert_100_to_C) {
    assert_arabic_to_roman_conversion(100, "C");
} END_TEST

START_TEST(convert_90_to_XC) {
    assert_arabic_to_roman_conversion(90, "XC");
} END_TEST

START_TEST(convert_50_to_L) {
    assert_arabic_to_roman_conversion(50, "L");
} END_TEST

START_TEST(convert_40_to_XL) {
    assert_arabic_to_roman_conversion(40, "XL");
} END_TEST

START_TEST(convert_30_to_XXX) {
    assert_arabic_to_roman_conversion(30, "XXX");
} END_TEST

START_TEST(convert_20_to_XX) {
    assert_arabic_to_roman_conversion(20, "XX");
} END_TEST

START_TEST(convert_10_to_X) {
    assert_arabic_to_roman_conversion(10, "X");
} END_TEST

START_TEST(convert_9_to_IX) {
    assert_arabic_to_roman_conversion(9, "IX");
} END_TEST

START_TEST(convert_5_to_V) {
    assert_arabic_to_roman_conversion(5, "V");
} END_TEST

START_TEST(convert_4_to_IV) {
    assert_arabic_to_roman_conversion(4, "IV");
} END_TEST

START_TEST(convert_3_to_III) {
    assert_arabic_to_roman_conversion(3, "III");
} END_TEST

START_TEST(convert_2_to_II) {
    assert_arabic_to_roman_conversion(2, "II");
} END_TEST

START_TEST(convert_1_to_I) {
    assert_arabic_to_roman_conversion(1, "I");
} END_TEST

START_TEST(handle_longest_roman_value_3888_to_MMMDCCCLXXXVIII) {
    ck_assert_int_eq(roman_to_arabic("MMMDCCCLXXXVIII"), 3888);
} END_TEST

START_TEST(reject_invalid_character_patterns) {
    ck_assert_int_eq(0,roman_to_arabic(""));
    ck_assert_int_eq(0,roman_to_arabic("MMMM"));
    ck_assert_int_eq(0,roman_to_arabic("IIII"));
    ck_assert_int_eq(0,roman_to_arabic("VV"));
    ck_assert_int_eq(0,roman_to_arabic("XXXX"));
    ck_assert_int_eq(0,roman_to_arabic("LL"));
    ck_assert_int_eq(0,roman_to_arabic("CCCC"));
    ck_assert_int_eq(0,roman_to_arabic("DD"));
    ck_assert_int_eq(0,roman_to_arabic("MMMM"));
    ck_assert_int_eq(0,roman_to_arabic("1"));
    ck_assert_int_eq(0,roman_to_arabic("a"));
    ck_assert_int_eq(0,roman_to_arabic("A"));
    ck_assert_int_eq(0,roman_to_arabic("IIIV"));
    ck_assert_int_eq(0,roman_to_arabic("VX"));
    ck_assert_int_eq(0,roman_to_arabic("VL"));
    ck_assert_int_eq(0,roman_to_arabic("VC"));
    ck_assert_int_eq(0,roman_to_arabic("VM"));
    ck_assert_int_eq(0,roman_to_arabic("XXL"));
    ck_assert_int_eq(0,roman_to_arabic("XXC"));
    ck_assert_int_eq(0,roman_to_arabic("XXD"));
    ck_assert_int_eq(0,roman_to_arabic("XXM"));
    ck_assert_int_eq(0,roman_to_arabic("LC"));
    ck_assert_int_eq(0,roman_to_arabic("LD"));
    ck_assert_int_eq(0,roman_to_arabic("LM"));
    ck_assert_int_eq(0,roman_to_arabic("CCD"));
    ck_assert_int_eq(0,roman_to_arabic("CCM"));
    ck_assert_int_eq(0,roman_to_arabic("DM"));
} END_TEST


Suite * roman_numeral_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("roman_numeral");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, convert_I_to_1);
    tcase_add_test(tc_core, convert_II_to_2);
    tcase_add_test(tc_core, convert_III_to_3);
    tcase_add_test(tc_core, convert_V_to_5);
    tcase_add_test(tc_core, convert_IV_to_4);
    tcase_add_test(tc_core, convert_IX_to_9);
    tcase_add_test(tc_core, convert_X_to_10);
    tcase_add_test(tc_core, convert_XX_to_20);
    tcase_add_test(tc_core, convert_XXX_to_30);
    tcase_add_test(tc_core, convert_L_to_50);
    tcase_add_test(tc_core, convert_XL_to_40);
    tcase_add_test(tc_core, convert_C_to_100);
    tcase_add_test(tc_core, convert_CC_to_200);
    tcase_add_test(tc_core, convert_CCC_to_300);
    tcase_add_test(tc_core, convert_XC_to_90);
    tcase_add_test(tc_core, convert_D_to_500);
    tcase_add_test(tc_core, convert_CD_to_400);
    tcase_add_test(tc_core, convert_M_to_1000);
    tcase_add_test(tc_core, convert_MM_to_2000);
    tcase_add_test(tc_core, convert_MMM_to_3000);
    tcase_add_test(tc_core, convert_CMXCIX_to_999);
    tcase_add_test(tc_core, convert_XLIX_to_49);
    tcase_add_test(tc_core, reject_invalid_character_patterns);
    tcase_add_test(tc_core, convert_3000_to_MMM);
    tcase_add_test(tc_core, convert_2000_to_MM);
    tcase_add_test(tc_core, convert_1000_to_M);
    tcase_add_test(tc_core, convert_900_to_CM);
    tcase_add_test(tc_core, convert_500_to_D);
    tcase_add_test(tc_core, convert_400_to_CD);
    tcase_add_test(tc_core, convert_300_to_CCC);
    tcase_add_test(tc_core, convert_200_to_CC);
    tcase_add_test(tc_core, convert_100_to_C);
    tcase_add_test(tc_core, convert_90_to_XC);
    tcase_add_test(tc_core, convert_50_to_L);
    tcase_add_test(tc_core, convert_40_to_XL);
    tcase_add_test(tc_core, convert_30_to_XXX);
    tcase_add_test(tc_core, convert_20_to_XX);
    tcase_add_test(tc_core, convert_10_to_X);
    tcase_add_test(tc_core, convert_9_to_IX);
    tcase_add_test(tc_core, convert_5_to_V);
    tcase_add_test(tc_core, convert_4_to_IV);
    tcase_add_test(tc_core, convert_3_to_III);
    tcase_add_test(tc_core, convert_2_to_II);
    tcase_add_test(tc_core, convert_1_to_I);
    tcase_add_test(tc_core, handle_longest_roman_value_3888_to_MMMDCCCLXXXVIII);
    tcase_add_test(tc_core, handle_longest_roman_value_MMMDCCCLXXXVIII_to_3888);
    

    suite_add_tcase(s, tc_core);

    return s;
}
