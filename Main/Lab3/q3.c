/*
Q: Write a program by using an user defined function for computing ⌊ √n⌋ for any positive integer n.
    Besides assignment and comparison, your algorithm may only use the four basic arithmetical operations.
*/

#include<stdio.h>
int square_root(int n){
    if(n == 0 | n == 1){
        return n;
    }    
    int ans = 0;
    int l = 1 , r = n;
    while(l<=r){
        int mid = (l + r)/2;
        if(mid * mid == n)return mid;
        if(mid * mid <=n){
            ans = mid;
            l = mid + 1;
        }   
        else r = mid - 1;
    }
    return ans;
}

int main(){
    int n;
    printf("Enter any +ve integer to find floor value of its root: ");
    scanf("%d",&n);
    printf("Floor value of its root = %d\n",square_root(n));
    return 0;
}