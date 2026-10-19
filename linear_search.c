#include <string.h>
#include <stdio.h>


int main(void)
{
    int num[] = {1, 3, 5,6,6, 7,2, 3,6,9,0};
    for (int i =0 ; i < 11; i++)
    {
        if (num[i] == 0)
        {
            printf("found");
            return 0;
        }
    }
    printf("not found");
    return 1;
}
