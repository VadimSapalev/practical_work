#include <stdio.h>

// Функція для підрахунку кількості послідовностей довжиною n, де не зустрічається три одиниці підряд
int countSequences(int n) {
    const int MOD = 12345;

    // Початкові значення для n = 1
    int a = 1; // кількість послідовностей, що закінчуються на 0
    int b = 1; // кількість послідовностей, що закінчуються на 1
    int c = 0; // кількість послідовностей, що закінчуються на 2 одиниці

    for (int i = 2; i <= n; i++) {
        int new_a = (a + b + c) % MOD;
        int new_b = a;
        int new_c = b;

        a = new_a;
        b = new_b;
        c = new_c;
    }

    return (a + b + c) % MOD;
}

int main() {
    int n;
    printf("Введіть довжину послідовностей n (1 < n < 10000): ");
    scanf("%d", &n);

    if (n <= 1 || n >= 10000) {
        printf("Неправильне значення n. Повинно бути 1 < n < 10000.\n");
        return 1;
    }

    int result = countSequences(n);
    printf("Кількість шуканих послідовностей довжиною %d: %d\n", n, result);

    return 0;
}
