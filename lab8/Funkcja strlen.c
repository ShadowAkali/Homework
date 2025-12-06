#include <stdio.h>
int my_strlen(const char s[]);
int main(void)
{
    char buffer[100];
    printf("Podaj tekst: ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        printf("Blad wczytywania.\n");
        return 1;
    }
    int length = my_strlen(buffer);
    /* Usuń znak nowej linii jeśli jest obecny */
    if (length > 0 && buffer[length - 1] == '\n') {
        buffer[length - 1] = '\0';
        length--;
    }
    printf("Dlugosc twojego tekstu to: %d znakow.\n", length);
    return 0;
}
int my_strlen(const char s[])
{
    int count = 0;
    while (s[count] != '\0') {
        count++;
    }
    return count;
}
