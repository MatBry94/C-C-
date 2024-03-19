
#include <stdio.h>

int main() {
int x = 10;
int *ptr;

ptr = &x;

*ptr = 20;

printf("Wartosc zmiennej x: %d\n", x);

printf("Wartosc zmiennej x (przez wskaznik): %d\n", *ptr);

return 0;

}