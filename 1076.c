#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VERTICES 50 

int movimentos; 
int V_total;
int adj[MAX_VERTICES][MAX_VERTICES];
int visitado[MAX_VERTICES]; 

void dfs_labirinto(int u) {
    visitado[u] = 1;
    
    for (int v = 0; v < V_total; v++) {
        if (adj[u][v] == 1 && visitado[v] == 0) {
            movimentos++;
            dfs_labirinto(v);
        }
    }
}

void resolve_caso() {
    int N_inicio;
    int A;
    int u, v;

    if (scanf("%d", &N_inicio) != 1) return;
    if (scanf("%d %d", &V_total, &A) != 2) return;

    movimentos = 0;
    
    for (int i = 0; i < V_total; i++) {
        visitado[i] = 0;
        for (int j = 0; j < V_total; j++) {
            adj[i][j] = 0;
        }
    }

    for (int i = 0; i < A; i++) {
        if (scanf("%d %d", &u, &v) != 2) return;
        
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    
    dfs_labirinto(N_inicio);
    
    printf("%d\n", movimentos * 2); 
}

int main() {
    int T;

    if (scanf("%d", &T) != 1) return 0;

    while (T--) {
        resolve_caso();
    }

    return 0;
}
