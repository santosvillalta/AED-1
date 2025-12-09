#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;
vector<int> g[MAXN], gt[MAXN];
bool visited[MAXN];

int N, M;

void dfs(int u) {
    visited[u] = true;
    for (int v : g[u])
        if (!visited[v]) dfs(v);
}

void dfsT(int u) {
    visited[u] = true;
    for (int v : gt[u])
        if (!visited[v]) dfsT(v);
}

int main() {
    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;

        for (int i = 1; i <= N; i++) {
            g[i].clear();
            gt[i].clear();
        }

        for (int i = 0; i < M; i++) {
            int V, W, P;
            cin >> V >> W >> P;

            g[V].push_back(W);
            gt[W].push_back(V);

            if (P == 2) {
                g[W].push_back(V);
                gt[V].push_back(W);
            }
        }

        memset(visited, 0, sizeof(visited));
        dfs(1);
        bool ok = true;

        for (int i = 1; i <= N; i++)
            if (!visited[i]) ok = false;

        memset(visited, 0, sizeof(visited));
        dfsT(1);

        for (int i = 1; i <= N; i++)
            if (!visited[i]) ok = false;

        cout << (ok ? 1 : 0) << "\n";
    }

    return 0;
}
