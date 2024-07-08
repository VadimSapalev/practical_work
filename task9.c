#include <stdio.h>
#include <limits.h>

int minSteps(int x, int y) {
    // Ініціалізуємо масив для зберігання мінімальної кількості кроків до кожного числа від x до y
    int minSteps[y + 1];
    
    // Заповнюємо масив значеннями, що вище максимального INT_MAX
    for (int i = 0; i <= y; i++) {
        minSteps[i] = INT_MAX;
    }
    
    // Перший крок - x, крок 0
    minSteps[x] = 0;
    
    // Обчислюємо мінімальну кількість кроків до кожного числа від x до y
    for (int i = x; i <= y; i++) {
        if (minSteps[i] != INT_MAX) {
            // Можливі наступні кроки: i+1, i-1, 2*i
            if (i + 1 <= y) {
                if (minSteps[i + 1] > minSteps[i] + 1) {
                    minSteps[i + 1] = minSteps[i] + 1;
                }
            }
            if (i - 1 >= x) {
                if (minSteps[i - 1] > minSteps[i] + 1) {
                    minSteps[i - 1] = minSteps[i] + 1;
                }
            }
            if (2 * i <= y) {
                if (minSteps[2 * i] > minSteps[i] + 1) {
                    minSteps[2 * i] = minSteps[i] + 1;
                }
            }
        }
    }
    
    // Повертаємо мінімальну кількість кроків до y
    return minSteps[y];
}

int main() {
    int x, y;
    
    // Введення x та y
    printf("Введіть значення x та y (0 <= x <= y < 2^31): ");
    scanf("%d %d", &x, &y);
    
    // Обчислення мінімальної кількості кроків
    int result = minSteps(x, y);
    printf("Мінімальна кількість кроків: %d\n", result);
    
    return 0;
}
