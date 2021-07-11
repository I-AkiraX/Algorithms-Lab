/*
Q: Let A be n*n square matrix array. WAP by using appropriate user defined functions for the following:
a) Find the number of nonzero elements in A
b) Find the sum of the elements above the leading diagonal.
c) Display the elements below the minor diagonal.
d) Find the product of the diagonal elements.
*/

#include <stdio.h>
int countNonZeroes(int arr[100][100], int n){
    int numOfNonZeroes = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (arr[i][j] != 0)
                numOfNonZeroes++;
        }
    }
    return numOfNonZeroes;
}
int productOfDiagonal(int arr[100][100], int n){
    int mult = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j || (i + j) == (n - 1)){
                mult *= arr[i][j];
            }
        }
    }
    return mult;
}
int sumOfElemAboveLeadDiag(int arr[100][100], int n){
    int sumOfElem = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (j>i){
                sumOfElem += arr[i][j];
                
            }
        }
    }
    return sumOfElem;
}
void printElemBelowMinorDiag(int arr[100][100], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if ((i + j) > (n - 1)){
                printf("%d\t",arr[i][j]);
            } else{
                printf("x\t");
            }
        }
        printf("\n");
    }
}
void main(){
    int arr[100][100], n;
    printf("Enter the size of matrix:  ");
    scanf("%d", &n);
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Number of Non Zero elements:  %d", countNonZeroes(arr, n));
    printf("\nSum of the elements above the leading diagonal:  %d\n", sumOfElemAboveLeadDiag(arr, n));
    printElemBelowMinorDiag(arr,n);
    printf("\nProduct of Diagonal:  %d", productOfDiagonal(arr, n));
}