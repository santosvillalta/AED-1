#include <stdio.h>
#include <string.h>

#define MAXN 2010
#define MAXM 20010

int head[MAXN];
int to[MAXM];
int next_edge[MAXM];
int edge_cnt;

int match[MAXN];
int vis[MAXN];
int vis_token;

void init_graph(int n) {
    for (int i = 0; i <= n; i++) head[i] = -1;
    edge_cnt = 0;
}

void add_edge(int u, int v) {
    to[edge_cnt] = v;
    next_edge[edge_cnt] = head[u];
    head[u] = edge_cnt++;
}

int dfs(int u) {
    vis[u] = vis_token;
    for (int e = head[u]; e != -1; e = next_edge[e]) {
        int v = to[e];
        if (match[v] == -1 || (vis[match[v]] != vis_token && dfs(match[v]))) {
            match[v] = u;
            return 1;
        }
    }
    return 0;
}

int main() {
    int N, M;
    while (scanf("%d %d", &N, &M) == 2) {
        init_graph(N);
        
        for (int i = 0; i < M; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            add_edge(u, v);
        }

        for (int i = 0; i <= N; i++) {
            match[i] = -1;
            vis[i] = 0;
        }
        
        int matching = 0;
        vis_token = 0;

        for (int i = 1; i <= N; i++) {
            vis_token++;
            if (dfs(i)) {
                matching++;
            }
        }

        printf("%d\n", N - matching);
    }
    return 0;
}
