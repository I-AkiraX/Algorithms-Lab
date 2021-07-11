/*
Q: Write a program that takes three variable (a, b, c) as separate parameters and rotates the values stored
so that value a goes to be, b, b to c and c to a by using SWAP(x,y) function that swaps/exchanges the numbers x & y.
*/

#include <stdio.h>
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
void main(){
    int a, b, c;
    printf("Enter 3 numbers:\n");
    scanf("%d%d%d", &a, &b, &c);
    printf("a = %d\nb = %d\nc = %d", a, b, c);
    swap(&a, &b);
    swap(&a, &c);
    printf("\n\nAfter Swapping:\na = %d\nb = %d\nc = %d", a, b, c);
}