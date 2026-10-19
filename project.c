#include<stdio.h>
#include<conio.h>
#include<string.h>

int main() {

    char ch;
    char pass[20], saved_pass[20];
    int i = 0;
    ch = getch();
    start:
    while (1) {
        if (ch==13) {
            pass[i] = '\0';
            break;
        }
        else {
            pass[i++] = ch;
            printf("*");
        } 
    }

    printf("You Entered : %s\n ", pass);

    FILE *ptr;
    ptr=fopen("password.text", "r");
    scanf(ptr, "%s", saved_pass);
    fclose(ptr);

    printf("Saved password %s\n", saved_pass);

    int l = strcmp(pass, saved_pass);
    if (l == 0) {
        printf("Login successfully/n");
    } 
    else {
        printf("Incorrect password\n");
    }
    goto start;

    return 0;
}
