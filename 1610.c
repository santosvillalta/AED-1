Com certeza\! Abaixo está o código em C para detecção de ciclos em dependências de documentos, com os comentários removidos, mantendo apenas a estrutura essencial e a lógica do programa.

## 💻 Código em C sem Comentários

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DOCUMENTS 10001 

enum State {
    NAO_VISITADO = 0,
    VISITADO_EM_CURSO = 1,
    PROCESSADO = 2
};

typedef struct Node {
    int data;          
    struct Node* next; 
} Node;

Node* adj_list[MAX_DOCUMENTS];
int document_state[MAX_DOCUMENTS];

void add_edge(int u, int v) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        exit(EXIT_FAILURE);
    }
    new_node->data = v;
    new_node->next = adj_list[u];
    adj_list[u] = new_node;
}

bool dfs(int u) {
    document_state[u] = VISITADO_EM_CURSO;

    Node* current = adj_list[u];
    while (current != NULL) {
        int v = current->data;

        if (document_state[v] == VISITADO_EM_CURSO) {
            return true;
        }

        if (document_state[v] == NAO_VISITADO) {
            if (dfs(v)) {
                return true;
            }
        }
        current = current->next;
    }

    document_state[u] = PROCESSADO;
    
    return false;
}

void cleanup(int N) {
    for (int i = 1; i <= N; i++) {
        Node* current = adj_list[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
        adj_list[i] = NULL;
    }
}

void solve() {
    int N, M;
    if (scanf("%d %d", &N, &M) != 2) return;

    for (int i = 1; i <= N; i++) {
        document_state[i] = NAO_VISITADO;
        adj_list[i] = NULL;
    }

    for (int i = 0; i < M; i++) {
        int A, B;
        if (scanf("%d %d", &A, &B) != 2) return;
        add_edge(A, B);
    }

    bool has_loop = false;
    
    for (int i = 1; i <= N; i++) {
        if (document_state[i] == NAO_VISITADO) {
            if (dfs(i)) {
                has_loop = true;
                break;
            }
        }
    }

    if (has_loop) {
        printf("SIM\n");
    } else {
        printf("NAO\n");
    }

    cleanup(N);
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 1;

    while (T--) {
        solve();
    }

    return 0;
}
```
