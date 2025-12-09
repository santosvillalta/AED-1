#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge { int to; };
struct Node { int total; int v; bool operator<(const Node &o) const { return total > o.total; } };

int main() {
    int N, M, K;
    double P;

    while (scanf("%d %d %d %lf", &N, &M, &K, &P) != EOF) {
        vector<int> atiradores(N+1,0);
        vector<vector<int>> g(N+1);

        for(int i=0;i<M;i++){
            int u,v;
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }

        int A;
        scanf("%d",&A);
        for(int i=0;i<A;i++){
            int pos;
            scanf("%d",&pos);
            atiradores[pos]++;
        }

        int start,end;
        scanf("%d %d",&start,&end);

        // Dijkstra: custo = numero de atiradores
        vector<int> dist(N+1, 1e9);
        priority_queue<Node> pq;
        dist[start] = atiradores[start];
        pq.push({dist[start], start});

        while(!pq.empty()){
            Node cur = pq.top(); pq.pop();
            int u = cur.v, d = cur.total;
            if(d > dist[u]) continue;

            for(int v: g[u]){
                int nd = dist[u] + atiradores[v];
                if(nd < dist[v]){
                    dist[v] = nd;
                    pq.push({nd,v});
                }
            }
        }

        double prob = 0.0;
        if(dist[end] <= K){
            prob = 1.0;
            for(int i=0;i<dist[end];i++)
                prob *= P;
        }

        printf("%.3lf\n", prob);
    }
    return 0;
}
