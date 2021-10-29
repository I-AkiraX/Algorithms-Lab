/*
Q: WAP to implement DFS algorithm
*/

#include <stdio.h>
#include <limits.h>
#include <time.h>

int vis[100] = {};
int g[100][100] = {};

void dfs(int node, int n)
{
    printf("%d ", node);
    vis[node] = 1;
    for (int j = 0; j < n; j++)
    {
        if (vis[j] == 0 && g[node][j] == 1)
        {
            dfs(j, n);
        }
    }
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
    dfs(src, n);
    time = clock() - time;
    double time_taken = ((double)time) / CLOCKS_PER_SEC;
    printf("\nTotal time = %lf\n", time_taken);

    return 0;
}