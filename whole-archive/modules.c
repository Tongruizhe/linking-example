#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "modules.h"

modules_list_t modules_list = {
    .name = 0,
    .next = NULL,
};

modules_list_t *get_module_by_name(const char *name) {
    modules_list_t *first = modules_list.next;
    while (first) {
        if (!strcmp(name, first->name))
            return first;
        first = first->next;
    }
    return NULL;
}

int register_module(modules_list_t *module) {
    if (!module) {
        printf("module not provided\n");
        return -1;
    }
    modules_list_t *first = &modules_list;
    while (first->next) {
        first = first->next;
    }
    first->next = module;
    module->next = NULL;
    printf("module: %s registers\n", module->name);
    return 0;
}