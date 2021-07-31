/*
Q: Let A be a list of n (not necessarily distinct) integers. Write a program by using User Defined Function(UDF)s
    to test whether any item occurs more than ⌈ n/2⌉ times in A.
    a) UDF should take O(n^2) time
    b) UDF should take O(n) time
*/

#include<stdio.h>
void count_freq(int n , int nums[n]){

    for(int i = 0 ; i<n ; i++){
        int count = 0;
        for(int j = 0 ; j<n ; j++){
            if(nums[j] == nums[i])count++;
            if(count>=(n/2)){
                printf("yes\n");
                return ;
            }
        }
    }
    printf("no\n");
}

void count_frequ(int n , int nums[n]){

    int count = 0;
    int candidate = -1;

    for(int i = 0 ; i<n ; i++){
        if(count == 0){
            candidate = nums[i];
        }
        count += (nums[i] == candidate) ? 1 : -1;
    }

    count = 0;

    for(int i = 0 ; i<n ; i++){
        if(nums[i] == candidate)count++;
    }

    if(count>=(n/2)){
        printf("yes\n");
    }
    else printf("no\n");
}   

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);

    int nums[n];
    printf("\nEnter the elements:\n");
    for(int i = 0 ; i<n ; i++){
        scanf("%d",&nums[i]);
    }

    count_freq(n,nums);
    count_frequ(n,nums);

    return 0;
}