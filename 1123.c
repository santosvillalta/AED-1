#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

typedef struct {
    int v, w;
} Edge;

typedef struct Node {
    Edge e;
    struct Node *next;
} Node;

Node *g[260];
int dist[260];
int used[260];

void addEdge(int u, int v, int w) {
    Node *n = malloc(sizeof(Node));
    n->e.v = v;
    n->e.w = w;
    n->next = g[u];
    g[u] = n;
}

int main() {
    int N, M, C, K;

    while (1) {
        scanf("%d %d %d %d", &N, &M, &C, &K);
        if (N==0 && M==0 && C==0 && K==0) break;

        for (int i = 0; i < N; i++) {
            g[i] = NULL;
            dist[i] = INF;
            used[i] = 0;
        }

        while (M--) {
            int u, v, p;
            scanf("%d %d %d", &u, &v, &p);

            int uIn = (u < C);
            int vIn = (v < C);

            if (uIn && vIn) {
                if (u + 1 == v) addEdge(u, v, p);
                if (v + 1 == u) addEdge(v, u, p);
            }
            else if (uIn) {
                addEdge(v, u, p);
            }
            else if (vIn) {
                addEdge(u, v, p);
            }
            else {
                addEdge(u, v, p);
                addEdge(v, u, p);
            }
        }

        dist[K] = 0;

        for (int i = 0; i < N; i++) {
            int u = -1, best = INF;
            for (int j = 0; j < N; j++) {
                if (!used[j] && dist[j] < best) {
                    best = dist[j];
                    u = j;
                }
            }
            if (u == -1) break;
            used[u] = 1;

            Node *cur = g[u];
            while (cur) {
                int v = cur->e.v, w = cur->e.w;
                if (dist[u] + w < dist[v]) dist[v] = dist[u] + w;
                cur = cur->next;
            }
        }

        printf("%d\n", dist[C-1]);
    }

    return 0;
}
