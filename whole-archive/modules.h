#ifndef _MODUELS_H_
#define _MODUELS_H_

#define MAX_LEN 256;

typedef struct modules_list {
    const char name[256];
    struct modules_list *next;
} modules_list_t;

modules_list_t *get_module_by_name(const char *name);

int register_module(modules_list_t *module);

#endif