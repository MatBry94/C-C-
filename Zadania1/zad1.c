#include <stdio.h>

int main() {
    char name[100]; 

    printf("Podaj swoje imie: ");
    scanf("%s", name);

    printf("Witaj, %s!\n", name); // Wypisujemy powitanie z imieniem

    return 0;
}