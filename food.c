#include <stdio.h>
#define MAX_LINES 100

int shortest_line_index(int lines[], int n) {
    //helper function to tell us which line is the shortest line.
    //takes:
    //  lines[] array contan the number of people in each line. 
    //  n the number of the lines
    //return : the index of the shortest line.
    //the run time is O(n)
    int j;
    int shortest = 0;
    for (j = 1; j < n; j++)
        if (lines[j] < lines[shortest])
            shortest = j;
    return shortest;
}

void solve(int lines[], int n, int m) {
    int i , shortest;
    for (i = 0; i < m; i++) {
        shortest = shortest_line_index(lines, n);
        printf("%d\n", lines[shortest]);
        lines[shortest]++;
    }
}

int main(void) {
    int lines[MAX_LINES];
    int n, m, i;
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
        scanf("%d", &lines[i]);
    solve(lines, n, m);
    return 0;
}
