/*
 * Copyright (C) Chen Xi.
 *
 * Unit Test module.
 * Written by Chen Xi <sunwhite@gmail.com> Jan 2023
 */

#include <check.h>
#include "wg_types.h"

int add(int x1, int x2)
{
    return 0;
}


START_TEST(test_add)
{
    fail_unless(add(2, 3) == 5, "error, 2 + 3 != 5");
}
END_TEST


Suite * make_add_suite(void)
{
    Suite *s = suite_create("add");
    TCase *tc_add = tcase_create("add");
    suite_add_tcase(s, tc_add);
    tcase_add_test(tc_add, test_add);
    return s;
}

int main(void)
{
    int n;
    SRunner * sr;
    sr = srunner_create(make_add_suite());
    srunner_run_all(sr, CK_NORMAL);
    n = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (n == 0) ? SUCCESS : FAILURE;
}
