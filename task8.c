#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Функція для обчислення факторіала
long long factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

// Функція для обчислення кількості анаграм
long long countAnagrams(char *word) {
    int length = strlen(word);
    
    // Масив для зберігання кількості кожної букви
    int freq[26] = {0};

    // Перетворюємо всі символи в слові до верхнього регістру
    for (int i = 0; i < length; i++) {
        word[i] = toupper(word[i]);
        freq[word[i] - 'A']++;
    }

    // Обчислюємо загальну кількість анаграм за формулою
    long long numerator = factorial(length);
    long long denominator = 1;

    // Обчислюємо добуток факторіалів кількостей кожної букви
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            denominator *= factorial(freq[i]);
        }
    }

    // Кількість анаграм
    return numerator / denominator;
}

int main() {
    char word[15]; // максимальна довжина слова 14, плюс завершальний нуль

    // Введення слова
    printf("Введіть слово (не більше 14 букв): ");
    scanf("%s", word);

    // Обчислення кількості анаграм
    long long result = countAnagrams(word);
    printf("Кількість анаграм для слова %s: %lld\n", word, result);

    return 0;
}
