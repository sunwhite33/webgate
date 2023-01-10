/*
 * Copyright (C) Chen Xi.
 *
 * Module management.
 * Written by Chen Xi <sunwhite@gmail.com> Jan 2023
 */

#include "list.h"

#define MAX_MODULE_NAME_LEN (64 - sizeof(unsigned long))

enum module_state
{
    MODULE_STATE_INIT ,      /* load module. */
    MODULE_STATE_LIVE,       /* running state. */
    MODULE_STATE_EXIT,      /* unload module. */
};

struct module
{
    /* name of this module */
    char name[MAX_MODULE_NAME_LEN];

    enum module_state state;

    /* Member of list of modules */
    struct list_head list;

    /* load function. */
    int (*init)(void);

    /* unload function. */
    void (*exit)(void);

};

