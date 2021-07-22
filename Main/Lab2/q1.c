/*
Q: Write a program to test whether a number n, entered through keyboard is prime or
    not by using different algorithms you know for atleast 10 inputs and note down the time
    complexity by step/frequency count method for each algorithm & for each input.
*/

#include <stdio.h>
#include <time.h>
#include<math.h>
void isPrime1(int x){
    int i = 2, d = 0;
    while (i < x){
        if (x % i == 0){
            d = 1;
            break;
        }
        i++;
    }
    printf("Number of comparisions:  %d\n\n", i - 2);
    printf("%d is ", x);
    if (d == 1 || x == 1){
        printf("not ");
    }
    printf("a prime number.");
}
int isPrime2(int n, int i){
    if (n == 1)
        return 0;
    if (i == 1){
        return 1;
    } else{
        if (n % i == 0){
            return 0;
        } else{
            return isPrime2(n, i - 1);
        }
    }
}
void isPrime3(int x){
    int d = 1;
    for (int i = 2; i <= sqrt(x); i++){
        if (x % i == 0){
            d = 0;
            break;
        }
    }
    printf("%d is ", x);
    if (d == 0 || x == 1){
        printf("not ");
    }
    printf("a prime number.");
}
void main(){
    int x;
    printf("Enter the number:  ");
    scanf("%d", &x);
    clock_t t;
    double countT;
    t = clock();
    isPrime1(x);
    t = clock() - t;
    countT=((double)t)/CLOCKS_PER_SEC;
    printf("\nPrime using while loop:  %f\n\n",countT);
    t = clock();
    isPrime3(x);
    t = clock() - t;
    countT=((double)t)/CLOCKS_PER_SEC;
    printf("\nPrime using square root:  %lf\n\n",countT);
    int i = x / 2;
    t = clock();
    if (isPrime2(x, i) == 1){
        printf("%d is a prime number", x);
    } else{
        printf("%d is not prime number", x);
    }
    t = clock() - t;
    countT=((double)t)/CLOCKS_PER_SEC;
    printf("\nPrime using recursion:  %f\n\n",countT);
}