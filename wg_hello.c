/*
 * Copyright (C) Chen Xi.
 *
 * Hello module.
 * Written by Chen Xi <sunwhite@gmail.com> Jan 2023
 */

#include <stdio.h>
#include "wg_module.h"

static int test_init(void)
{
    printf("test_init");
    return 0;

}

static void test_exit(void)
{
    printf("test_exit");
}

module_init(test_init);
module_exit(test_exit);
