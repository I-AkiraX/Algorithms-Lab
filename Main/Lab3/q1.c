/*
Q: Compare the best case, worst case and average case time complexity of Insertion Sort on basis of Step Count Method as well as CPU clock time.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertion_sort(int *a,int n){
    int count = 0;
    int key,j;
    for(int i = 1; i<n; i++){
        key = a[i];
        j=i-1;

        while(j>=0&&a[j]>key)
        {
            a[j+1]=a[j];
            j=j-1;
            count++;
        }
        a[j+1]=key;
    }

    printf("\nStep Count : %d",count);
}

int main()
{
    //int best[10],worst[10],average[10];
    int best[10]={1,2,3,4,5,6,7,8,9,10};
    int worst[10]={10,9,8,7,6,5,4,3,2,1};
    int average[10]={1,10,2,8,3,7,4,6,5,5};
    clock_t begin,end;

    printf("\n\n WORST CASE INSERTION SORT \n");
    printf("Original Array : ");
    for (int i=0; i<10;i++)
    {
        printf(" %d ",worst[i]);
    }
    begin=clock();
    insertion_sort(worst,10);
    end=clock();
    printf("\nSorted Array : ");
    for (int i=0; i<10;i++)
    {
        printf(" %d ",worst[i]);
    }
    printf("\nTime Consumed = %2.4f",(double)(end-begin));

     printf("\n\n AVERAGE CASE INSERTION SORT \n");
    printf("Original Array : ");
    for (int i=0; i<10;i++)
    {
        printf(" %d ",average[i]);
    }
    begin=clock();
    insertion_sort(average,10);
     end=clock();
       printf("\nTime Consumed = %2.4f",(double)(end-begin));
    printf("\nSorted Array : ");
    for (int i=0; i<10;i++)
    {
        printf(" %d ",average[i]);
    }

    printf("\n\n BEST CASE INSERTION SORT \n");
    printf("Original Array : ");
    for (int i=0; i<10;i++)
    {
        printf(" %d ",best[i]);
    }
       begin=clock();
    insertion_sort(best,10);
     end=clock();
      printf("\nTime Consumed = %2.4f",(double)(end-begin)*1000);
    printf("\nSorted Array : ");
    for (int i=0; i<10;i++)
    {
        printf(" %d ",best[i]);
    }
}