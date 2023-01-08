/*
 * Copyright (C) Chen Xi.
 *
 * Module management.
 * Written by Chen Xi <sunwhite@gmail.com> Jan 2023
 */

enum module_state
{
    MODULE_STATE_LIVE,    /* Normal state. */
    MODULE_STATE_COMING,    /* Full formed, running module_init. */
    MODULE_STATE_GOING,    /* Going away. */
    MODULE_STATE_UNFORMED,    /* Still setting it up. */
};

struct module
{
    enum module_state state;

    /* Member of list of modules */
    struct list_head list;

    /* Unique handle for this module */
    char name[MODULE_NAME_LEN];

    /* Sysfs stuff. */
    struct module_kobject mkobj;
    struct module_attribute *modinfo_attrs;
    const char *version;
    const char *srcversion;
    struct kobject *holders_dir;

    /* Exported symbols */
    const struct kernel_symbol *syms;
    const s32 *crcs;
    unsigned int num_syms;

    /* Startup function. */
    int (*init)(void);

    /* Destruction function. */
    void (*exit)(void);

};

