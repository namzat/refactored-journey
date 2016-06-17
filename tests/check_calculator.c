#include <stdio.h>
#include "check_calculator.h"

Suite * calculator_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("calculator");

    /* Core test case */
    tc_core = tcase_create("Core");

    suite_add_tcase(s, tc_core);

    return s;
}