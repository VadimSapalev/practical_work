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
    int p;
    printf("Input size: ");
    scanf("%d", &p);
    
    if (p >= 2 && p <=20) {
        int nums[p];
        for (int i = 0; i < p; i++) {
            scanf("%d", &nums[i]);
        }
    
        int result = nums[0];
        for (int i = 1; i < p; i++) {
            result = lcm(result, nums[i]);
        }
    
        printf("%d\n", result);
    }
    else {
        printf("Not supported size");
    }
    return 0;
}
