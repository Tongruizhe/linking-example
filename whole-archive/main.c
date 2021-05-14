#include <stdio.h>
#include <stdlib.h>
#include "modules.h"

int main() {
    modules_list_t *m = get_module_by_name("module_A");
    if (m) {
        printf("module_A found\n");
    } else
        printf("Not found\n");
    exit(0);
}