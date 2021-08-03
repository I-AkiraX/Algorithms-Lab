/*
Q: Write a program to search an element x in an array of n integers using binary search
    algorithm that uses divide and conquer technique. Find out the best case, worst case
    and average case time complexities for different values of n and plot a graph of the
    time taken versus n. The n integers can be generated randomly and x can be chosen
    randomly, or any element of the array or middle or last element of the array depending on type of time complexity analysis.
*/

#include <stdio.h>
#include <stdlib.h>
int count = 0;
int binary(int arr[], int l, int r, int x, int c1, int c2){
    if (r >= l){
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x){
            c1 = c1 + 1;
            return binary(arr, l, mid - 1, x, c1, c2);
        }
        c2 = c2 + 1;
        count = c1 + c2;
        return binary(arr, mid + 1, r, x, c1, c2);
    }
    count = c1 + c2;
    return -1;
}
void ascending(int number[], int n){
    int i, j, a;
    for (i = 0; i < n; ++i){
        for (j = i + 1; j < n; ++j){
            if (number[i] > number[j]){
                a = number[i];
                number[i] = number[j];
                number[j] = a;
            }
        }
    }
}
void main(){
    int r, n, x;
    printf("Enter the value of n:- ");
    scanf("%d", &n);
    int arr[100];
    for (int i = 0; i < n; i++)
        arr[i] = rand();
    ascending(arr, n);
    printf("Array Elements:- ");
    for (int i = 0; i < n; i++)
        printf("%d\n", arr[i]);
    printf("\n");
    printf("Enter the value to search:- ");
    scanf("%d", &x);
    r = binary(arr, 0, n - 1, x, 0, 0);
    printf("Time Complexity:- %d\n", count);
    if (r == -1)
        printf("Element is not present.");
    else
        printf("Element is present at index %d", r);
}