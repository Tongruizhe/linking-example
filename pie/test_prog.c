#include <unistd.h>
#include <stdio.h>

const char s[] = "hello world";
int sleep_second = 10000000;

int main() {
    printf("%s, sleep %d seconds", s, sleep_second);   
    sleep(sleep_second);
    return 0;
}
