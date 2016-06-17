#include <stdio.h>
#include "check_calculator.h"
#include "../src/calculator.h"

START_TEST(I_plus_I_returns_II) {
    ck_assert_str_eq(add("I", "I"), "II");
} END_TEST

Suite * calculator_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("calculator");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, I_plus_I_returns_II);
    suite_add_tcase(s, tc_core);

    return s;
}