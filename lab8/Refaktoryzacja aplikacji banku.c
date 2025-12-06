#include <stdio.h>
#define MAX_ACCOUNTS 100
/* PROTOTYPY */
void print_menu(void);
void deposit(double saldo[], int n);
void withdraw(double saldo[], int n);
void show_balance(const double saldo[], int n);
/* ---------------- MAIN ---------------- */
int main(void)
{
    double saldo[MAX_ACCOUNTS] = {0.0};
    int choice;
    do {
        print_menu();
        printf("Wybór: ");
        if (scanf("%d", &choice) != 1) {
            printf("Błąd danych.\n");
            return 1;
        }
        switch (choice)
        {
        case 1:
            deposit(saldo, MAX_ACCOUNTS);
            break;
        case 2:
            withdraw(saldo, MAX_ACCOUNTS);
            break;
        case 3:
            show_balance(saldo, MAX_ACCOUNTS);
            break;
        case 0:
            printf("Koniec programu.\n");
            break;
        default:
            printf("Niepoprawna opcja.\n");
            break;
        }
    } while (choice != 0);
    return 0;
}
/* ---------------- FUNKCJE ---------------- */
void print_menu(void)
{
    printf("\nMENU:\n");
    printf("1 – DEPOSIT\n");
    printf("2 – WITHDRAW\n");
    printf("3 – SHOW BALANCE\n");
    printf("0 – EXIT\n");
}
void deposit(double saldo[], int n)
{
    int acc;
    double amount;
    printf("Numer konta: ");
    scanf("%d", &acc);
    if (acc < 0 || acc >= n) {
        printf("DEPOSIT ERROR. Konto poza zakresem.\n");
        return;
    }
    printf("Kwota: ");
    scanf("%lf", &amount);
    saldo[acc] += amount;
    printf("DEPOSIT OK. Konto %d nowe saldo: %.2f\n", acc, saldo[acc]);
}
void withdraw(double saldo[], int n)
{
    int acc;
    double amount;
    printf("Numer konta: ");
    scanf("%d", &acc);
    if (acc < 0 || acc >= n) {
        printf("WITHDRAW ERROR. Konto poza zakresem.\n");
        return;
    }
    printf("Kwota: ");
    scanf("%lf", &amount);
    if (saldo[acc] < amount) {
        printf("WITHDRAW ERROR. Brak srodkow.\n");
        return;
    }
    saldo[acc] -= amount;

    printf("WITHDRAW OK. Konto %d nowe saldo: %.2f\n", acc, saldo[acc]);
}
void show_balance(const double saldo[], int n)
{
    int acc;
    printf("Numer konta: ");
    scanf("%d", &acc);
    if (acc < 0 || acc >= n) {
        printf("SHOW ERROR. Konto poza zakresem.\n");
        return;
    }
    printf("SHOW: Konto %d saldo = %.2f\n", acc, saldo[acc]);
}
