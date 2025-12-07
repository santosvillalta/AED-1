#include <stdio.h>

int N, M;
char g[1025][1025];
int vis[1025][1025];

int qx[2000000], qy[2000000];

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%s", g[i]);

    int ans = 0;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (g[i][j] == '.' && !vis[i][j]) {
                ans++;
                int h = 0, t = 0;
                qx[t] = i; qy[t] = j; t++;
                vis[i][j] = 1;

                while (h < t) {
                    int x = qx[h], y = qy[h];
                    h++;
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                            if (g[nx][ny] == '.' && !vis[nx][ny]) {
                                vis[nx][ny] = 1;
                                qx[t] = nx;
                                qy[t] = ny;
                                t++;
                            }
                        }
                    }
                }
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
