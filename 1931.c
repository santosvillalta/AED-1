#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

#define INF 0x3f3f3f3f

struct Edge {
    int to, w;
};

vector<Edge> adj[10005];
int dist[10005][2];

int main() {
    int C, V;
    while (scanf("%d %d", &C, &V) != EOF) {

        // Limpa o grafo
        for (int i = 1; i <= C; i++) adj[i].clear();

        // Lê as estradas
        for (int i = 0; i < V; i++) {
            int a, b, g;
            scanf("%d %d %d", &a, &b, &g);
            adj[a].push_back({b, g});
            adj[b].push_back({a, g});
        }

        // Dijkstra: dist[city][paridade]
        for (int i = 1; i <= C; i++) {
            dist[i][0] = dist[i][1] = INF;
        }

        priority_queue< 
            pair<int, pair<int,int>>, 
            vector<pair<int, pair<int,int>>>, 
            greater<pair<int, pair<int,int>>> 
        > pq;

        // Começa em cidade 1 com 0 pedágios → paridade 0
        dist[1][0] = 0;
        pq.push({0, {1, 0}}); // {custo, {cidade, paridade}}

        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            int d = top.first;
            int u = top.second.first;
            int parity = top.second.second;

            if (d > dist[u][parity]) continue;

            for (auto e : adj[u]) {
                int v = e.to;
                int w = e.w;
                int newParity = 1 - parity;   // alterna (par ↔ ímpar)

                if (dist[v][newParity] > d + w) {
                    dist[v][newParity] = d + w;
                    pq.push({dist[v][newParity], {v, newParity}});
                }
            }
        }

        // Resultado: cidade C com paridade PAR (0)
        if (dist[C][0] >= INF)
            printf("-1\n");
        else
            printf("%d\n", dist[C][0]);
    }
    return 0;
}
