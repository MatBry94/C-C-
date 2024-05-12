#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100 


typedef struct {
    char imie[50];
    char nazwisko[50];
    char numer_telefonu[20];
} Contact;


void dodaj_kontakt(Contact* ksiazka, int* liczba_kontaktow) {
    if (*liczba_kontaktow >= MAX_CONTACTS) {
        printf("Ksiazka adresowa jest pelna!\n");
        return;
    }

    printf("Podaj imie: ");
    scanf_s("%s", ksiazka[*liczba_kontaktow].imie);
    printf("Podaj nazwisko: ");
    scanf_s("%s", ksiazka[*liczba_kontaktow].nazwisko);
    printf("Podaj numer telefonu: ");
    scanf_s("%s", ksiazka[*liczba_kontaktow].numer_telefonu);

    (*liczba_kontaktow)++;
}


void wyszukaj_kontakt(const Contact* ksiazka, int liczba_kontaktow, const char* nazwisko) {
    for (int i = 0; i < liczba_kontaktow; i++) {
        if (strcmp(ksiazka[i].nazwisko, nazwisko) == 0) {
            printf("Znaleziono kontakt:\n");
            printf("Imie: %s\n", ksiazka[i].imie);
            printf("Nazwisko: %s\n", ksiazka[i].nazwisko);
            printf("Numer telefonu: %s\n", ksiazka[i].numer_telefonu);
            return;
        }
    }
    printf("Nie znaleziono kontaktu o nazwisku %s\n", nazwisko);
}


void usun_kontakt(Contact* ksiazka, int* liczba_kontaktow, const char* nazwisko) {
    int znaleziono = 0;
    for (int i = 0; i < *liczba_kontaktow; i++) {
        if (strcmp(ksiazka[i].nazwisko, nazwisko) == 0) {
            for (int j = i; j < *liczba_kontaktow - 1; j++) {
                ksiazka[j] = ksiazka[j + 1];
            }
            (*liczba_kontaktow)--;
            znaleziono = 1;
            printf("Kontakt o nazwisku %s zostal usuniety.\n", nazwisko);
            break;
        }
    }
    if (!znaleziono) {
        printf("Nie znaleziono kontaktu o nazwisku %s\n", nazwisko);
    }
}


void wypisz_kontakty(const Contact* ksiazka, int liczba_kontaktow) {
    printf("Ksiazka adresowa:\n");
    for (int i = 0; i < liczba_kontaktow; i++) {
        printf("%d. %s %s, numer telefonu: %s\n", i + 1, ksiazka[i].imie, ksiazka[i].nazwisko, ksiazka[i].numer_telefonu);
    }
}

int main() {
    Contact ksiazka[MAX_CONTACTS]; 
    int liczba_kontaktow = 0; 

    char wybor;
    char nazwisko[50];

    printf("Witaj w ksiazce adresowej!\n");

    while (1) {
        printf("\nCo chcesz zrobic?\n");
        printf("1. Dodaj kontakt\n");
        printf("2. Znajdz kontakt\n");
        printf("3. Usun kontakt\n");
        printf("4. Wyswietl wszystkie kontakty\n");
        printf("5. Zakoncz program\n");

        scanf_s(" %c", &wybor);

        switch (wybor) {
        case '1':
            dodaj_kontakt(ksiazka, &liczba_kontaktow);
            break;
        case '2':
            printf("Podaj nazwisko do wyszukania: ");
            scanf_s("%s", nazwisko);
            wyszukaj_kontakt(ksiazka, liczba_kontaktow, nazwisko);
            break;
        case '3':
            printf("Podaj nazwisko do usuniecia: ");
            scanf_s("%s", nazwisko);
            usun_kontakt(ksiazka, &liczba_kontaktow, nazwisko);
            break;
        case '4':
            wypisz_kontakty(ksiazka, liczba_kontaktow);
            break;
        case '5':
            printf("Koniec programu.\n");
            return 0;
        default:
            printf("Niepoprawna opcja. Wybierz ponownie.\n");
        }
    }

    return 0;
}