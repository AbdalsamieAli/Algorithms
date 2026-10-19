#include <stdio.h>

typedef char *str;

int main(void) {
    str s = "Hi!";
    char *p = &s[0];
    printf("%p\n", s);
    printf("%p\n", p);
} 
