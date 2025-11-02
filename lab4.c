#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int k;
    printf("Podaj dodatnią liczbę całkowitą k: ");
    if (scanf("%d", &k) != 1) {
        fprintf(stderr, "Niepoprawne dane wejściowe.\n");
        return 1;
    }
    if (k <= 0) {
        fprintf(stderr, "k musi być większe od 0.\n");
        return 1;
    }
    printf("Liczby z przedziału 50-100 podzielne przez %d:\n", k);
    int found = 0;
    for (int i = 50; i <= 100; ++i) {
        if (i % k == 0) {
            printf("%d\n", i);
            found = 1;
        }
    }
    if (!found) {
        printf("Brak liczb podzielnych przez %d w przedziale 50-100.\n", k);
    }
    return 0;
}