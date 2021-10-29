/*
Q: WAP to implement BFS algorithm
*/

#include <stdio.h>
#include <limits.h>
#include <time.h>
int vis[100] = {};
int g[100][100] = {};

void bfs(int src, int n)
{
    int arr[n + 1];

    int l = 0, r = 1;

    arr[0] = src;

    vis[src] = 1;

    while (l < r)
    {
        int node = arr[l++];

        printf("%d ", node);

        for (int j = 0; j < n; j++)
        {
            if (g[node][j] == 1 && vis[j] == 0)
            {
                arr[r++] = j;
                vis[j] = 1;
            }
        }
    }

    printf("\n");
}
int main()
{
    int roll = 1905330;
    int src = (roll % 10);

    int n;
    int m;
    n = 10; // Nodes
    m = 16; // Edges
    g[0][1] = 1;
    g[0][3] = 1;
    g[0][4] = 1;
    g[1][2] = 1;
    g[1][4] = 1;
    g[2][5] = 1;
    g[3][4] = 1;
    g[3][6] = 1;
    g[4][5] = 1;
    g[4][7] = 1;
    g[5][9] = 1;
    g[6][4] = 1;
    g[6][7] = 1;
    g[7][5] = 1;
    g[7][8] = 1;
    g[8][9] = 1;

    clock_t time;
    time = clock();
    bfs(src, n);
    time = clock() - time;
    double time_taken = ((double)time) / CLOCKS_PER_SEC;
    printf("Total time = %lf\n", time_taken);

    return 0;
}