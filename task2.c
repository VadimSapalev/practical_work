#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int n;
    printf("Input size");
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int result = nums[0];
    for (int i = 1; i < n; i++) {
        result = lcm(result, nums[i]);
    }

    printf("%d\n", result);

    return 0;
}
