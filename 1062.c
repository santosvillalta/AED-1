#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1005

typedef struct {
    int items[MAX_N];
    int topo;
} Pilha;

void stack_init(Pilha *s) {
    s->topo = -1;
}

void stack_push(Pilha *s, int x) {
    if (s->topo < MAX_N - 1) {
        s->items[++s->topo] = x;
    }
}

int stack_top(Pilha *s) {
    if (s->topo != -1) {
        return s->items[s->topo];
    }
    return -1;
}

void stack_pop(Pilha *s) {
    if (s->topo != -1) {
        s->topo--;
    }
}

int stack_empty(Pilha *s) {
    return s->topo == -1;
}


int verifica_permutacao(int N, const int saida[]) {
    Pilha estacao;
    stack_init(&estacao);
    
    int vagao_chegando = 1; 
    int saida_idx = 0; 
    
    while (saida_idx < N) {
        
        int vagao_desejado = saida[saida_idx];
        
        while (vagao_chegando <= N && (stack_empty(&estacao) || stack_top(&estacao) != vagao_desejado)) {
            stack_push(&estacao, vagao_chegando);
            vagao_chegando++;
        }
        
        if (!stack_empty(&estacao) && stack_top(&estacao) == vagao_desejado) {
            stack_pop(&estacao);
            saida_idx++;
        } else {
            return 0;
        }
    }
    
    return 1;
}

int main() {
    int N;
    
    while (scanf("%d", &N) == 1 && N != 0) {
        
        while (1) {
            
            int primeiro_vagao;
            if (scanf("%d", &primeiro_vagao) != 1) break;
            
            if (primeiro_vagao == 0) break; 
            
            int saida[MAX_N];
            saida[0] = primeiro_vagao;
            
            for (int i = 1; i < N; i++) {
                if (scanf("%d", &saida[i]) != 1) break;
            }

            if (verifica_permutacao(N, saida)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
        
        printf("\n"); 
    }

    return 0;
}
