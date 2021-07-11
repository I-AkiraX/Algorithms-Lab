/*
Q: Write a program to rearrange the elements of an array of n integers such that all even
numbers are followed by all odd numbers. How many different ways you can solve this
problem. Write your approaches & strategy for solving this problem.
*/

#include <stdio.h>
void main(){
    int n, arr[500],count;
    printf("Enter the number of elements of the array:  ");
    scanf("%d", &n);
    printf("Enter the elements of the array: \n");
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    count = 0;
    for (int i = 0; i < n; i++){
        if(arr[i] %2 == 0){
            count++;
            int x = arr[i];
            int d = arr[count - 1];
            arr[count - 1] = x;
            arr[i] = d;
        }
    }
    printf("New array:  ");
    for(int i = 0; i< n; i++){
        printf("%d  ", arr[i]);
    }
}