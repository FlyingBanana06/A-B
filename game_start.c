#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

int choose_mode() {
    int ans = 0;
    while (scanf("%d", &ans) == 0 || (ans != 1 && ans != 2)) {
        printf("Invalid input. Please enter 1 or 2!\n");
        while (getchar() != '\n'); // clear \n or wrong input
    }
    while (getchar() != '\n');

    printf("Mode %d selected!\n", ans);
    return ans;
}

char* get_test_case() {
    int total = 1, len = get_length();
    for (int i = 0; i < len; i++) total *= 3;

    // set random number
    srand(time(NULL));
    int num = (rand() + 60001) % total;
    
    static char ans[11] = {};
    generate_test_case(len, num, ans);
    return ans;
}

int get_length() {
    int ans = 0;
    while (scanf("%d", &ans) == 0 || (ans < 3 || ans > 10)) {
        printf("Invalid input. Please enter a number between 3 and 10!\n");
        while (getchar() != '\n'); // clear \n or wrong input
    }
    while (getchar() != '\n');
    return ans;
}

void generate_test_case(int len, int num, char ans[11]) {
    // operates in ternary
    // explain in decimal
    // ex: no.123456, output: abcdef
    // doing it backwards, pick 6 first, by % 10, fill 'f' in ans[5]
    // then / 10, do 5, 4, 3...
    for (int i = len - 1; i >= 0; i--) {
        switch (num % 3) {
            case 0: ans[i] = 'a'; break;
            case 1: ans[i] = 'b'; break;
            case 2: ans[i] = 'c';
        }
        num /= 3;
    }    
}

int compare(const void *a, const void *b) {
    return (*(char *)a - *(char *)b); // Sort by ASCII value from smallest to largest
}

char* get_answer(char test[11]) {
    static char ans[11] = {};
    strcpy(ans, test);
    qsort(ans, strlen(ans), sizeof(char), compare);
    return ans;
}