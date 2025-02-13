#include <stdio.h>

int check_password_timing_leak(char input[], char correct[]) {
    int i = 0;
    while (correct[i]) {
        if (input[i] != correct[i]) {  // Branch based on secret
            return 0;  // Wrong password
        }
        i++;
    }
    return 1;  // Correct password
}

int secure_check_without_timing_leak(char input[], char correct[], int len) { //Execution time is constant, regardless of input.
    int diff = 0;
    for (int i = 0; i < len; i++) {
        diff |= input[i] ^ correct[i];  // No branching with use of bitwise XOR instead of an if condition.
    }
    return diff == 0;
}
