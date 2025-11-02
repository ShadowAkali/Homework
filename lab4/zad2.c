#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int dni, start;
    printf("Podaj liczbę dni w miesiącu: ");
    if (scanf("%d", &dni) != 1 || dni <= 0) {
        fprintf(stderr, "Niepoprawna liczba dni.\n");
        return 1;
    }
    printf("Podaj dzień tygodnia, od którego zaczyna się miesiąc (1–Niedziela, 7–Sobota): ");
    if (scanf("%d", &start) != 1 || start < 1 || start > 7) {
        fprintf(stderr, "Niepoprawny dzień tygodnia.\n");
        return 1;
    }
    printf("\nKalendarz miesiąca:\n\n");
    // Wydruk pustych pól przed pierwszym dniem
    for (int i = 1; i < start; i++) {
        printf("    ");
    }
    // Drukujemy dni miesiąca w jednej pętli
    for (int d = 1; d <= dni; d++) {
        printf("%4d", d);
        // Po każdym siódmym dniu tygodnia przechodzimy do nowej linii
        if ((d + start - 1) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
    return 0;
}
