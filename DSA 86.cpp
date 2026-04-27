#include <stdio.h>


long long integerSquareRoot(long long n) {
    if (n < 2) {
        return n;
    }

    long long low = 0;
    long long high = n;
    long long ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long square = mid * mid;

        if (square == n) {
            return mid; 
        } 
        else if (square < n) {
            ans = mid;     
            low = mid + 1;
        } 
        else {
            high = mid - 1; 
        }
    }

    return ans;
}

int main() {
    long long n;
    if (scanf("%lld", &n) == 1) {
        printf("%lld\n", integerSquareRoot(n));
    }
    return 0;
}
