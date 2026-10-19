#include <stdio.h>

struct Person {
    char name[20];
    int age;
};

int main(void) {
    struct Person person = {"Alice", 25};
    struct Person *ptr = &person;
    printf("Name: %s, Age: %d\n", ptr->name, ptr->age);
    printf("Name: %s, Age: %d\n", (*ptr).name, (*ptr).age);
}