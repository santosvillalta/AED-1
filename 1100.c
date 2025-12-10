#include <stdio.h>
#include <string.h>

typedef struct {
    int r, c, d;
} Node;

int dr[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dc[] = {1, 2, 2, 1, -1, -2, -2, -1};

int bfs(int r1, int c1, int r2, int c2) {
    int visited[8][8];
    memset(visited, 0, sizeof(visited));

    Node q[100];
    int front = 0, rear = 0;

    q[rear++] = (Node){r1, c1, 0};
    visited[r1][c1] = 1;

    while (front < rear) {
        Node curr = q[front++];

        if (curr.r == r2 && curr.c == c2) return curr.d;

        for (int i = 0; i < 8; i++) {
            int nr = curr.r + dr[i];
            int nc = curr.c + dc[i];

            if (nr >= 0 && nr < 8 && nc >= 0 && nc < 8 && !visited[nr][nc]) {
                visited[nr][nc] = 1;
                q[rear++] = (Node){nr, nc, curr.d + 1};
            }
        }
    }
    return 0;
}

int main() {
    char s1[5], s2[5];

    while (scanf("%s %s", s1, s2) != EOF) {
        int c1 = s1[0] - 'a';
        int r1 = s1[1] - '1';
        int c2 = s2[0] - 'a';
        int r2 = s2[1] - '1';

        int moves = bfs(r1, c1, r2, c2);

        printf("To get from %s to %s takes %d knight moves.\n", s1, s2, moves);
    }

    return 0;
}
