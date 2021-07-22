/*
Q: Write a program to find out GCD (greatest common divisor) using Euclid’s algorithm
*/

#include <stdio.h>
#include <time.h>
void euclid_gcd(int x, int y){
    while (y > 0){
        int r = x % y;
        x = y;
        y = r;
    }
    printf("GCD = %d \n", x);
}
void consecutive_int_checking_gcd(int x, int y){
    int c;
    c = x >= y ? y : x;
    for (int i = c; i >= 1; i--){
        if (x % i == 0 && y % i == 0){
            printf("GCD = %d\n", i);
            break;
        }
    }
}
void middle_school_gcd(int x, int y){
    int c, ans = 1, m, n;
    c = x >= y ? y : x;
    for (int i = 2; i < c; i++){
        n = 0;
        m = 0;
        if (x % i == 0){
            n = 1;
            x /= i;
        }
        if (y % i == 0){
            m = 1;
            y /= i;
        }
        if (n == 1 && m == 1){
            ans *= i;
        }
        if (n == 1 || m == 1)
            i--;
    }
    printf("GCD = %d\n", ans);
}
void main(){
    int a, b;
    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);
    clock_t t;
    double countT;
    t = clock();
    euclid_gcd(a, b);
    t = clock() - t;
    countT = ((double)t) / CLOCKS_PER_SEC;
    printf("Euclid's algorithm:  %f\n\n", countT);
    t = clock();
    consecutive_int_checking_gcd(a, b);
    t = clock() - t;
    countT = ((double)t) / CLOCKS_PER_SEC;
    printf("Consecutive Integer checking:  %f\n\n", countT);
    t = clock();
    middle_school_gcd(a, b);
    t = clock() - t;
    countT = ((double)t) / CLOCKS_PER_SEC;
    printf("Middle school procedure:  %f\n\n", countT);
}