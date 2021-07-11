/*
Q: Write a program to store numbers into an array of n integers, where the array
must cotains some duplicates. Do the following:
a) Find out the total number of duplicate elements.
b) Find out the most repeating element in the array.
*/

#include <stdio.h>
void main(){
    int n, count, arr[500], largestD[2], duplicateE[500];
    printf("Enter the number of elements of the array:  ");
    scanf("%d", &n);
    printf("Enter the elements of the array (Make sure to enter a few duplicate ones): \n");
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    largestD[0] = 0;
    largestD[1] = 0;
    count = 0;
    for (int i = 0; i < n; i++){
        int flag = 1;
        for (int x = 0; x < count; x++){
            if (arr[i] == duplicateE[x]){
                flag = 0;
                break;
            }
        }
        if (flag == 1){
            int noa = 0;
            for (int j = 0; j < n; j++){
                if (arr[i] == arr[j])
                    noa++;
            }
            if (noa > 1){
                if (largestD[0] < noa){
                    largestD[0] = noa;
                    largestD[1] = arr[i];
                }
                duplicateE[count] = arr[i];
                count++;
            }
        }
    }
    printf("Number of duplicate elements:  %d\nElement with largest number of occurances:  %d:- %d occurances", count, largestD[1], largestD[0]);
}