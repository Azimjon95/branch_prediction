#include <stdio.h>
#include <time.h>

int main() {
    int arr[1000000], sum = 0;
    for (int i = 0; i < 1000000; i++) arr[i] = i % 2; // Unpredictable pattern

    clock_t start = clock();
    for (int i = 0; i < 1000000; i++) {
        if (arr[i] == 0) sum++;
    }
    clock_t end = clock();

    printf("Execution Time: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}
