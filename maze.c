#include <stdio.h>
int visited[10][10], count;
void findpath(int a [10][10], int row, int col, int n);
void main()
{
    int a[10][10], row, col, i, j, n;
    printf("Enter the size of the maze:\n");
    scanf("%d", &n);
    printf("Enter the elements of the maze:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the starting point:\n");
    scanf("%d%d", &row, &col);
    if (a[row][col] == 0)
    {
        printf("No Path");
        return;
    }
    findpath(a, row, col, n);
    if (count == 0)
    {
        printf("No Path");
        return;
    }
}
void findpath(int a[10][10], int row, int col, int n)
{
    if (row == n - 1 && col == n - 1)
    {
        count++;
        visited[row][col] = 1;
        printf("Solution: %d\n", count);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d ", visited[i][j]);
            }
            printf("\n");
        }
        visited[row][col] = 0;
    }
    else
    {
        visited[row][col] = 1;
    }
    if (row - 1 >= 0 && visited[row - 1][col] == 0 && a[row - 1][col] == 1)
    {
        findpath(a, row - 1, col, n);
    }
    if (row + 1 < n && visited[row + 1][col] == 0 && a[row + 1][col] == 1)
    {
        findpath(a, row + 1, col, n);
    }
    if (col - 1 >= 0 && visited[row][col - 1] == 0 && a[row][col - 1] == 1)
    {
        findpath(a, row, col - 1, n);
    }
    if (col + 1 < n && visited[row][col + 1] == 0 && a[row][col + 1] == 1)
    {
        findpath(a, row, col + 1, n);
    }
    visited[row][col] = 0;
}