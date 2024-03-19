#include <stdio.h> 

struct Point {
float x;
float y;
};
void zmienWspl(struct Point* p, float new_x, float new_y) {
p->x = new_x;
p->y = new_y;
}

struct Rectangle {
struct Point topleft;
struct Point bottomright;
};

float poleProstokata(struct Rectangle r){
float width = r.bottomright.x - r.topleft.x;
float height = r.topleft.y - r.bottomright.y;
return width * height;
}

float obwodProstokata(struct Rectangle r) {
float width = r.bottomright.x - r.topleft.x;
float hight = r.topleft.y - r.bottomright.y;
return 2 * (width + hight);
}

int main() {
struct Point p = { 3.5, 4.2 };
zmienWspl(&p, 6.8, 9.1);
printf("Nowe wspolrzedne punktu: (%.2f, %.2f)\n", p.x, p.y);

struct Rectangle prostokat = { {2.0, 4.0},{6.0,2.0} };

printf("Pole prostokata: %2f\n", poleProstokata(prostokat));
printf("Obwod prostokata: %2f\n", obwodProstokata(prostokat));

return 0;


}