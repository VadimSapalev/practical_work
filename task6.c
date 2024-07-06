#include <stdio.h>
#include <math.h>

int main() {
    int x1, y1, x2, y2;
    
    // Введення координат початку та кінця вектора
    printf("Введіть координати x1, y1, x2, y2: ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    // Обчислення довжини вектора
    double length = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    // Виведення результату з точністю до шести знаків після коми
    printf("Довжина вектора: %.6f\n", length);

    return 0;
}
