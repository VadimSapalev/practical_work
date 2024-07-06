#include <stdio.h>
#include <math.h>

// Функція для визначення кількості точок перетину двох кіл
int intersectionPoints(int x1, int y1, int r1, int x2, int y2, int r2) {
    // Відстань між центрами кіл
    double d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    // Перевірка на випадки
    if (x1 == x2 && y1 == y2 && r1 == r2) {
        // Кола збігаються
        return -1;
    } else if (d > r1 + r2 || d < fabs(r1 - r2)) {
        // Кола не перетинаються
        return 0;
    } else if (d == r1 + r2 || d == fabs(r1 - r2)) {
        // Кола торкаються (зовні або зсередини)
        return 1;
    } else {
        // Кола мають дві точки перетину
        return 2;
    }
}

int main() {
    int x1, y1, r1, x2, y2, r2;
    
    // Введення координат центрів та радіусів кіл
    printf("Введіть координати x1, y1, r1, x2, y2, r2: ");
    scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

    // Визначення кількості точок перетину
    int result = intersectionPoints(x1, y1, r1, x2, y2, r2);
    printf("Кількість точок перетину: %d\n", result);

    return 0;
}
