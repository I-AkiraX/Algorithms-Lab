/*
Q: Write a program to store numbers into an array of n integers and then find out
the smallest and largest number stored in it. n is the user input.
*/

#include <stdio.h>
void main(){
    int n, arr[500];
    printf("Enter the number of elements of the array:  ");
    scanf("%d", &n);
    printf("Enter the elements of the array: \n");
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int smallest = arr[0];
    for (int i = 1; i < n; i++){
        if (arr[i] < smallest)
            smallest = arr[i];
    }
    int largest = arr[0];
    for (int i = 1; i < n; i++){
        if (arr[i] > largest)
            largest = arr[i];
    }
    printf("Smallest:  %d\nLargest:  %d", smallest, largest);
}