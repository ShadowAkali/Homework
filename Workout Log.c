#include <stdio.h>
#include <string.h>

#define MAX_TRAININGS 100
#define TYPE_LEN 20
typedef struct {
    int training_id;
    int day;
    int month;
    int year;
    char type[TYPE_LEN];
    int minutes;
} Training;
Training trainings[MAX_TRAININGS];
int training_count = 0;

/* ---------- WALIDACJA ---------- */

int valid_date(int d, int m, int y) {
    if (y < 1900 || m < 1 || m > 12 || d < 1) return 0;

    int days_in_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0))
        days_in_month[1] = 29;

    return d <= days_in_month[m - 1];
}

int id_exists(int id) {
    for (int i = 0; i < training_count; i++) {
        if (trainings[i].training_id == id)
            return 1;
    }
    return 0;
}
/* ---------- OPERACJE ---------- */
void add_training() {
    if (training_count >= MAX_TRAININGS) {
        printf("Brak miejsca na nowe treningi.\n");
        return;
    }

    Training t;

    printf("ID treningu: ");
    scanf("%d", &t.training_id);

    if (id_exists(t.training_id)) {
        printf("Blad: ID juz istnieje.\n");
        return;
    }

    printf("Data (dd mm rrrr): ");
    scanf("%d %d %d", &t.day, &t.month, &t.year);

    if (!valid_date(t.day, t.month, t.year)) {
        printf("Blad: niepoprawna data.\n");
        return;
    }

    printf("Typ aktywnosci (bez spacji): ");
    scanf("%19s", t.type);

    printf("Czas w minutach: ");
    scanf("%d", &t.minutes);

    if (t.minutes <= 0) {
        printf("Blad: czas musi byc dodatni.\n");
        return;
    }

    trainings[training_count++] = t;
    printf("Dodano trening.\n");
}
void remove_training() {
    int id;
    printf("Podaj ID do usuniecia: ");
    scanf("%d", &id);

    for (int i = 0; i < training_count; i++) {
        if (trainings[i].training_id == id) {
            trainings[i] = trainings[training_count - 1];
            training_count--;
            printf("Usunieto trening.\n");
            return;
        }
    }
    printf("Blad: nie znaleziono ID.\n");
}
void list_by_month() {
    int m, y;
    printf("Podaj miesiac i rok: ");
    scanf("%d %d", &m, &y);

    int found = 0;
    for (int i = 0; i < training_count; i++) {
        if (trainings[i].month == m && trainings[i].year == y) {
            Training t = trainings[i];
            printf("ID:%d %02d-%02d-%d %s %d min\n",
                   t.training_id, t.day, t.month, t.year, t.type, t.minutes);
            found = 1;
        }
    }
    if (!found)
        printf("Brak treningow w tym miesiacu.\n");
}
void total_time_month() {
    int m, y;
    printf("Podaj miesiac i rok: ");
    scanf("%d %d", &m, &y);

    int sum = 0;
    for (int i = 0; i < training_count; i++) {
        if (trainings[i].month == m && trainings[i].year == y)
            sum += trainings[i].minutes;
    }

    printf("Laczny czas: %d minut\n", sum);
}

void total_time_type() {
    char type[TYPE_LEN];
    printf("Podaj typ aktywnosci: ");
    scanf("%19s", type);

    int sum = 0;
    for (int i = 0; i < training_count; i++) {
        if (strcmp(trainings[i].type, type) == 0)
            sum += trainings[i].minutes;
    }

    printf("Laczny czas dla %s: %d minut\n", type, sum);
}

void report_longest() {
    if (training_count == 0) {
        printf("Brak danych.\n");
        return;
    }

    int max = 0;
    for (int i = 1; i < training_count; i++) {
        if (trainings[i].minutes > trainings[max].minutes)
            max = i;
    }

    Training t = trainings[max];
    printf("Najdluzszy trening: ID %d, %s, %d minut\n",
           t.training_id, t.type, t.minutes);
}

void report_most_common_type() {
    if (training_count == 0) {
        printf("Brak danych.\n");
        return;
    }

    int max_count = 0;
    char best[TYPE_LEN] = "";

    for (int i = 0; i < training_count; i++) {
        int count = 0;
        for (int j = 0; j < training_count; j++) {
            if (strcmp(trainings[i].type, trainings[j].type) == 0)
                count++;
        }
        if (count > max_count) {
            max_count = count;
            strcpy(best, trainings[i].type);
        }
    }

    printf("Najczestszy typ aktywnosci: %s (%d treningow)\n",
           best, max_count);
}
/* ---------- MENU ---------- */
void menu() {
    printf("\n--- DZIENNIK TRENINGOW ---\n");
    printf("1. Dodaj trening\n");
    printf("2. Usun trening\n");
    printf("3. Wypisz treningi z miesiaca\n");
    printf("4. Laczny czas w miesiacu\n");
    printf("5. Laczny czas dla typu\n");
    printf("6. Najdluzszy trening\n");
    printf("7. Najczestszy typ aktywnosci\n");
    printf("0. Wyjscie\n");
}

int main() {
    int choice;
    do {
        menu();
        printf("Wybor: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_training(); break;
            case 2: remove_training(); break;
            case 3: list_by_month(); break;
            case 4: total_time_month(); break;
            case 5: total_time_type(); break;
            case 6: report_longest(); break;
            case 7: report_most_common_type(); break;
            case 0: printf("Koniec programu.\n"); break;
            default: printf("Nieznana opcja.\n");
        }
    } while (choice != 0);
    return 0;
}
