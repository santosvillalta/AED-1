#include <stdio.h>

int N, M;
char grid[1025][1025];
int visited[1025][1025];

void dfs(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= M) return;
    if (grid[x][y] != '.' || visited[x][y]) return;
    visited[x][y] = 1;
    dfs(x+1, y);
    dfs(x-1, y);
    dfs(x, y+1);
    dfs(x, y-1);
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%s", grid[i]);

    int count = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (grid[i][j] == '.' && !visited[i][j]) {
                dfs(i, j);
                count++;
            }

    printf("%d\n", count);
    return 0;
}
