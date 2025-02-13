#include <stdio.h>
#include <string.h>
#include <time.h>

// Insecure function (leaks timing information)
int insecureCheck(const char *input, const char *correct) {
    for (size_t i = 0; i < strlen(correct); i++) {
        if (input[i] != correct[i]) {
            return 0; // Timing leak occurs here
        }
    }
    return 1;
}

// Secure function (constant-time comparison)
int secureCheck(const char *input, const char *correct) {
    int diff = 0;
    size_t len = strlen(correct);
    
    for (size_t i = 0; i < len; i++) {
        diff |= input[i] ^ correct[i];  // No branching
    }
    
    return diff == 0;
}

int main() {
    const char *correctPassword = "secure123";
    const char *input = "secure123";

    // Measure time for insecure check
    clock_t start = clock();
    int result = insecureCheck(input, correctPassword);
    clock_t end = clock();
    printf("Insecure Check Time: %lu ns, Result: %s\\n", (end - start), result ? "Match" : "No Match");

    // Measure time for secure check
    start = clock();
    result = secureCheck(input, correctPassword);
    end = clock();
    printf("Secure Check Time: %lu ns, Result: %s\\n", (end - start), result ? "Match" : "No Match");

    return 0;
}
