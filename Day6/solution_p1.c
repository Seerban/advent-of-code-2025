#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// will give wrong answer if not enough space
#define BUF_SIZE 5000
#define MAX_NUMS_COL 1000
#define MAX_NUMS_ROW 20

int main() {
    FILE *f = fopen("input.txt", "r");
    char buf[BUF_SIZE];
    int nums[MAX_NUMS_ROW][MAX_NUMS_COL];

    // READ file into nums
    int row = 0;
    int col = 0;
    while(fgets(buf, BUF_SIZE, f)) {
        col = 0;

        // parse numbers from line
        char *idx = strtok(buf, " \n");
        while(idx != NULL) {
            // set to 0 for addition and 1 for mult, otherwise read num
            if( idx[0] == '+') nums[row][col] = 0;
            else if( idx[0] == '*') nums[row][col] = 1;
            else nums[row][col] = atoi(idx);
            
            col++;
            idx = strtok(NULL, " \n");
        }
        row++;
    }
    
    long long sum = 0;

    // read except symbol row
    for(int i = 0; i < col; ++i) {
        int addition = nums[row-1][i] == 0;

        // initialize 0 for sum and 1 for mult
        long long col_sum = addition ? 0 : 1;

        for(int j = 0; j < row-1; ++j)
            if( addition ) col_sum += nums[j][i];
            else col_sum *= nums[j][i];

        sum += col_sum;
        printf("Step %d : %lld\n", i, sum);
    }

    printf("%lld", sum);

    fclose(f);
    return 0;
}