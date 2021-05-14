#include "modules.h"
#include <stdio.h>

static modules_list_t moduleA = {
    .name = "module_A",
    .next = 0,
};

void __attribute__((constructor)) register_self() {
    printf("Call register_module to register myself\n");
    register_module(&moduleA);
}