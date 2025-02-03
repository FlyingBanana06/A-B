#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    printf("Welcome to the game \"A = B\"!\n");
    printf("Goal: Sort the strings in ascending order.\n");

    printf("\nPlease select a game mode (1 or 2):\n");
    printf("(Mode 1: Show the result after each step)\n");
    printf("(Mode 2: Show only the final result)\n");
    int mode = choose_mode();

    printf("\nPlease enter the length of the test case.\n");
    printf("(Minimum: 3, Maximum: 10)\n");
    char test[11] = {};
    strcpy(test, get_test_case());
    printf("\ntest: %s\n", test);

    printf("\nPlease enter all commands, and type \"exit\" when finished.\n");
    printf("(Maximum replacement length: 2, e.g., oo = xx)\n");
    printf("(Maximum number of commands: 5)\n");
    char output[11] = {};
    strcpy(output, test);
    process_command(output, mode);

    char answer[11] = {};
    strcpy(answer, get_answer(test, mode));
    
    printf("\nPlayer Output: %s\n", output);
    printf("Answer: %s\n", answer);
    printf("Game Result: ");
    if (strcmp(output, answer) == 0) {
        printf("Congratulations! Correct Answer!!\n");
    } else {
        printf("Oops, Wrong Answer\n");
    }

    system("pause");
    return 0;
}