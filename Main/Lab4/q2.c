/*
Q: Write a program to sort a list of n elements using the merge sort method and
    determine the time required to sort the elements. Repeat the experiment for
    different values of n and different nature of data (random data, sorted data,
    reversely sorted data) in the list. n is the user input and n integers can be
    generated randomly. Finally plot a graph of the time taken versus n.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
long inf = 1e9;
int comp = 0;
void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[100], R[100];
    L[n1] = inf;
    R[n2] = inf;
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        } else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r){
    if (l < r){
        comp++;
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
void descending(int number[], int n){
    int i, j, a;
    for (i = 0; i < n; ++i){
        for (j = i + 1; j < n; ++j){
            if (number[i] < number[j]){
                a = number[i];
                number[i] = number[j];
                number[j] = a;
            }
        }
    }
}
void printArray(int A[], int size){
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
void main(){
    int n;
    int arr[50], x;
    printf("enter array size:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        arr[i] = rand();
    double time_taken;
    printf("\n\nArray Before Sorting: \n");
    printArray(arr, n);
    clock_t time = clock();
    mergeSort(arr, 0, n - 1);
    printf("Array after sorting:-\n");
    printArray(arr, n);
    time = clock() - time;
    time_taken = ((double)time) / CLOCKS_PER_SEC;
    printf("The no of times it is looped for random data:- %d\n", comp);
    printf("Total Time = %f\n", time_taken);
    comp = 0;
    printf("\n\nArray Before Sorting: \n");
    printArray(arr, n);
    clock_t time0 = clock();
    mergeSort(arr, 0, n - 1);
    printf("Array after sorting:-\n");
    printArray(arr, n);
    time0 = clock() - time0;
    time_taken = ((double)time0) / CLOCKS_PER_SEC;
    printf("The no of times it is looped for ascending data:- %d\n", comp);
    printf("Total Time = %f\n", time_taken);
    descending(arr, n);
    comp = 0;
    printf("\n\nArray Before Sorting: \n");
    printArray(arr, n);
    clock_t time1 = clock();
    mergeSort(arr, 0, n - 1);
    printf("Array after sorting:-\n");
    printArray(arr, n);
    time1 = clock() - time1;
    time_taken = ((double)time1) / CLOCKS_PER_SEC;
    printf("The no of times it is looped for descending data:- %d\n", comp);
    printf("Total Time = %f\n", time_taken);
}