/*
 Program for finding the squre root of number using itraive algorithm.

Input :
    number
Output :
    Squre Root of the number
 */

#include <stdio.h> 
#include <stdlib.h> 

float squrerootof(int n) {
	float x, y;
	int i = 0;
	x = n/2;
	while (i < 100000) {
	    
            y = (x + n/x) / 2;
	    if (((y - x) < 0.0001) && ((y - x) > 0)) return y;
	    x = y;
	    i++;
	
	};

	return y;
};



int main(int argc, char *argv[]) {
	if (argc > 1) {
            char *a = argv[1];
            int n = atoi(a);
            float s = squrerootof(n);
            printf("The squre root of %i is %.6f\n", n, s);
	    return 0;
	};
	printf("Enter number as command line argmument.\n");

};
