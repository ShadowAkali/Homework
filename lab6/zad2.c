#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Podaj liczbe elementow (n >= 2): ");
    scanf("%d", &n);
    if (n < 2) {
        printf("BLAD: za malo danych aby policzyc roznice (n musi byc >= 2).\n");
        return 0;
    }
    int t[n];  // VLA – tablica o rozmiarze podanym przez użytkownika
    printf("Wpisz %d liczb calkowitych:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }
    int max_diff = abs(t[1] - t[0]);
    for (int i = 1; i < n - 1; i++) {
        int diff = abs(t[i + 1] - t[i]);
        if (diff > max_diff) {
            max_diff = diff;
        }
    }
    printf("MAX_DIFF = %d\n", max_diff);
    return 0;
}
