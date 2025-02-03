#include <stdio.h>
#include <string.h>
#include "functions.h"

void process_command(char ans[11], int mode) {
    for (int i = 0; i < 5; i++) {
        char cmd[15] = {}, A[3] = {}, B[3] = {};
        gets(cmd);
        if (strcmp(cmd, "exit") == 0) break;

        if (parse_command(cmd, A, B) == 1) { // if input invalid, reread command
            printf("Invalid input. Please enter the command in the format \"oo = xx\"\n");
            i--;
            continue;
        }

        replace_string(ans, A, B);
        if (mode == 1) {
            printf("Result: %s\n", ans);
        }
    }
}

int parse_command(char cmd[8], char A[3], char B[3]) {    
    int i;
    for (i = 0; cmd[i] != ' '; i++) {
        if (cmd[i] == '\0' || i > 1) return 1; // check invalid input "ab" (no " = ") or "abc = def" (> 3)
        A[i] = cmd[i]; // scan A
    }

    if (cmd[++i] != '=') return 1; // check invalid input " "
    i += 2; // skip "= "
    
    int j;
    for (j = 0; cmd[i + j] != '\0'; j++) B[j] = cmd[i + j]; // scan B

    if (i - 3 != j) return 1; // check invalid input "a = de" (A_length != B_length)
    return 0;
}

void replace_string(char ans[11], char A[3], char B[3]) {
    for (int i = 0; i < 10; i++) {
        char* find = strstr(ans, A);
        if (find == NULL) return;
        int n = find - ans; // found place (ex: xxxx ooo xxxxx, n = 3)

        char after[11] = {}; // save string after check (ex: xxxx xxx ooooo)
        n += strlen(A); // the start of after check (ex: xxxx xxx ooooo, n = 7)
        for (int j = 0; j < (strlen(ans) - n); j++) after[j] = ans[n + j];

        n -= strlen(A); // the start of replace (ex: xxxx ooo xxxxx, n = 5)
        for (int j = 0; j < strlen(B); j++) ans[n + j] = B[j]; // replace

        n += strlen(B);
        for (int j = 0; j <= strlen(B); j++) ans[n + j] = after[j]; // add back after, need to save \0
    }
}