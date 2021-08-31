#include <stdio.h>
#include <time.h>
#include <stdlib.h>
clock_t start, end;
double cpu_time_used;
int randomiser = 0;
int *arr;
void generate(int n)
{
    randomiser++;
    srand(n + randomiser);
    free(arr);
    arr = (int *)malloc(n * sizeof(int));
    int i;
    for (i = 0; i < n; i++)
        *(arr + i) = rand();
}
void swap(int *x, int *y)
{
    int t = (*x);
    (*x) = (*y);
    (*y) = t;
}
void heapifylarge(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapifylarge(arr, n, largest);
    }
}
void minheapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifylarge(arr, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapifylarge(arr, i, 0);
    }
}
void heapifysmall(int arr[], int n, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] < arr[smallest])
        smallest = l;
    if (r < n && arr[r] < arr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&arr[i], &arr[smallest]);
        heapifysmall(arr, n, smallest);
    }
}
void maxheapSort(int arr[], int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapifysmall(arr, n, i);
    for (i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapifysmall(arr, i, 0);
    }
}
void printarr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("\n%d ", arr[i]);
    printf("\n");
}
void largest(int arr[], int n)
{
    int large = arr[0];
    int i;
    for (i = 0; i < n; i++)
        if (large < arr[i])
            large = arr[i];
    printf("\nLargest element is %d\n", large);
}
void sorting(int arr[], int n)
{
    maxheapSort(arr, n);
}
void replace(int arr[], int n)
{
    int node, value;
    printf("\nEnter node:");
    scanf("%d", &node);
    printf("\nEnter value:");
    scanf("%d", &value);
    arr[node] = value;
    sorting(arr, n);
}
void insert(int arr[], int *n)
{
    int new;
    int size = (*n) + 1;
    int *store = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < (*n); i++)
        *(store + i) = arr[i];
    printf("\nEnter new element:");
    scanf("%d", &new);
    *(store + size - 1) = new;
    generate(size);
    for (int i = 0; i < size; i++)
        arr[i] = *(store + i);
    *(n) = size;
    sorting(arr, *n);
}
int delete (int arr[], int *n)
{
    int node = -1, value;
    printf("\nEnter value to delete:");
    scanf("%d", &value);
    int i;
    for (i = 0; i < (*n); i++)
        if (arr[i] == value)
        {
            node = i;
            break;
        }
    if (node == -1)
    {
        printf("\nElement not found");
        return 1;
    }
    int *store = (int *)malloc(((*n) - 1) * sizeof(int));
    int j;
    for (i = 0, j = 0; i < (*n); i++)
        if (i != node)
        {
            *(store + j) = arr[i];
            j++;
        }
    generate((*n) - 1);
    *n = (*n) - 1;
    for (i = 0; i < (*n); i++)
        arr[i] = *(store + i);
    sorting(arr, *n);
    return 0;
}
void main()
{
    int n, choice = -1;
    arr = (int *)malloc(10000000 * sizeof(int));
    printf("\nEnter number of elements:");
    scanf("%d", &n);
    generate(n);
    while (choice != 0)
    {
        printf("\n\n\n0> Exit\n1> Generate\n2> Display\n3> Descending\n4> Ascending\n5> time to sort random data in ascending\n6> Time to sort ascending from ascending order\n7> Time to sort ascending from descending order\n8> Total time complexity\n9> Extract largest\n10> Replace value\n11> Insert a new element\n12> Delete an element\n\nEnter your choice:");
        scanf("%d", &choice);
        printf("\n\n");
        switch (choice)
        {
        case 0:
            return;
        case 1:
            printf("\nEnter number of elements:");
            scanf("%d", &n);
            generate(n);
            break;
        case 2:
            printarr(arr, n);
            break;
        case 3:
            maxheapSort(arr, n);
            break;
        case 4:
            minheapSort(arr, n);
            break;
        case 5:
            generate(n);
            start = clock();
            minheapSort(arr, n);
            end = clock();
            cpu_time_used = ((double)(end - start) / CLOCKS_PER_SEC);
            printf("%lf", cpu_time_used);
            break;
        case 6:
            minheapSort(arr, n);
            start = clock();
            minheapSort(arr, n);
            end = clock();
            cpu_time_used = ((double)(end - start) / CLOCKS_PER_SEC);
            printf("%lf", cpu_time_used);
            break;
        case 7:
            maxheapSort(arr, n);
            start = clock();
            minheapSort(arr, n);
            end = clock();
            cpu_time_used = ((double)(end - start) / CLOCKS_PER_SEC);
            printf("%lf", cpu_time_used);
            break;
        case 8:
            printf("\nElements\tData random\tData ascending\tData descending\n");
            int i;
            for (i = 5000; i <= 50000; i = i + 5000)
            {
                n = i;
                generate(n);
                printf("%d\t\t", i);
                start = clock();
                minheapSort(arr, n);
                end = clock();
                cpu_time_used = ((double)(end - start) / CLOCKS_PER_SEC);
                printf("%lf\t", cpu_time_used);
                start = clock();
                minheapSort(arr, n);
                end = clock();
                cpu_time_used = ((double)(end - start) / CLOCKS_PER_SEC);
                printf("%lf\t", cpu_time_used);
                maxheapSort(arr, n);
                start = clock();
                minheapSort(arr, n);
                end = clock();
                cpu_time_used = ((double)(end - start) / CLOCKS_PER_SEC);
                printf("%lf\n", cpu_time_used);
            }
            break;
        case 9:
            largest(arr, n);
            break;
        case 10:
            replace(arr, n);
            break;
        case 11:
            insert(arr, &n);
            break;
        case 12:
            delete (arr, &n);
            break;
        default:
            printf("\nWrong option entered.");
        }
    }
}