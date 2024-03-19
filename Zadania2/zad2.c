#include <stdio.h> 

void podwoj(float* ptr) {
	*ptr *= 2;
}

int main() {
	float x = 5.5;
	float* ptr = &x;

	podwoj(ptr);

	printf("Nowa wartosc zmiennej x: %.2f\n", x);

	return 0;
}