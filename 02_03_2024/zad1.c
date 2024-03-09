#include <stdio.h>

int main() {
    char name[100]; 

    printf("Podaj swoje imie i nazwisko : ");
    scanf("%s", name); 

    printf("Witaj, %s!\n", name); 

    return 0;
}