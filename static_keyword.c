#include <stdio.h>

int f(void){
    static int x = 5;
    printf("%d\n", x);
    x++;
}

int func(void){
    int x = 6;
    printf("%d\n", x);
    x++;
}

int main(void){
    func();
    func();
    func();
    return 0;
}

