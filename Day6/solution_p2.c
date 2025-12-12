#include <stdio.h>
#include <string.h>

#define BUF_SIZE 5000
#define BUF_COUNT 20

// note: added 1 whitespace to each line input (program adds to total at every blank column)
// solution stores entire input as char** but could be optimized with fseek

int main() {
    FILE *f;
    char bufs[BUF_COUNT][BUF_SIZE]; // store numbers & symbols
    
    f = fopen("input.txt", "r");
    
    int rows = 0; // row count
    while( fgets(bufs[rows], BUF_SIZE, f) ) ++rows;
    
    long long temp_sum = 0; // sum per oclumn
    long long total = 0; // result
        
    int addition = 0; // (1)adding or (0)multiplying
    int col = 0; // column index
    while(1) {
        if(bufs[0][col] == '\n') break;
        if(bufs[rows-1][col] == '+') {
            addition = 1;
            temp_sum = 0;
        }
        if(bufs[rows-1][col] == '*') {
            addition = 0;
            temp_sum = 1;
        }

        int num = 0;
        for(int i = 0; i < rows - 1; ++i)
            if(bufs[i][col] != ' ')
                num = num * 10 + (int)(bufs[i][col] - '0');

        // if at empty spacing column then add to total and reset
        if(num != 0)
            if(addition)
                temp_sum += num;
            else
                temp_sum *= num;
        else total += temp_sum;
        
        ++col;
    }

    fclose(f);
    printf("%lld", total);

    return 0;
}