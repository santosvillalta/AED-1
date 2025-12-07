#include <stdio.h>
#include <string.h>

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    for (int tc = 1; tc <= T; tc++) {
        int V, E;
        scanf("%d %d", &V, &E);
        int adj[26][26];
        int vis[26];
        memset(adj, 0, sizeof(adj));
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < E; i++) {
            char a, b;
            scanf(" %c %c", &a, &b);
            int x = a - 'a';
            int y = b - 'a';
            adj[x][y] = adj[y][x] = 1;
        }
        printf("Case #%d:\n", tc);
        int comps = 0;
        int stack[26];
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                comps++;
                int top = 0;
                stack[top++] = i;
                vis[i] = 1;
                int comp[26], cn = 0;
                while (top > 0) {
                    int u = stack[--top];
                    comp[cn++] = u;
                    for (int v = 0; v < V; v++) {
                        if (adj[u][v] && !vis[v]) {
                            vis[v] = 1;
                            stack[top++] = v;
                        }
                    }
                }
                int used[26];
                memset(used,0,sizeof(used));
                for (int k = 0; k < cn; k++) used[comp[k]] = 1;
                for (int k = 0; k < V; k++) if (used[k]) printf("%c,", 'a' + k);
                printf("\n");
            }
        }
        printf("%d connected components\n\n", comps);
    }
    return 0;
}
