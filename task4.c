#include <stdio.h>

int countEqualDivisors(int n) {
    int count = 0;

    // Перебираємо всі можливі значення m
    for (int m = 1; m < n; m++) {
        // Перевіряємо, чи є n = k * (m + 1) для деякого цілого k
        if (n % (m + 1) == 0) {
            int k = n / (m + 1);
            if (n % m == k) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int n;
    printf("Введіть натуральне число n (1 < n < 150): ");
    scanf("%d", &n);

    if (n <= 1 || n >= 150) {
        printf("Неправильне значення n. Повинно бути 1 < n < 150.\n");
        return 1;
    }

    int result = countEqualDivisors(n);
    printf("Кількість рівних дільників для числа %d: %d\n", n, result);

    return 0;
}
