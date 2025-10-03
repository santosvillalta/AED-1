#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPRESSAO 1005

typedef struct No {
    char caractere;
    struct No *prox;
} No;

void push(No **topo, char c) {
    No *novo = (No*)malloc(sizeof(No));
    
    if (novo == NULL) {
        exit(1);
    }
    
    novo->caractere = c;
    
    novo->prox = *topo;
    
    *topo = novo;
}

char pop(No **topo) {
    if (*topo == NULL) {
        return '\0'; 
    }
    
    No *temp = *topo;
    char c = temp->caractere;
    
    *topo = temp->prox;
    
    free(temp);
    
    return c;
}

int is_empty(No *topo) {
    return (topo == NULL);
}

void verifica_balanco_com_lista(const char *expressao) {
    No *pilha = NULL; 
    int erro_encontrado = 0;

    for (int i = 0; expressao[i] != '\0'; i++) {
        char c = expressao[i];

        if (c == '(') {
            push(&pilha, c);
        } 
        else if (c == ')') {
            if (is_empty(pilha)) {
                erro_encontrado = 1;
                break;
            }
            pop(&pilha);
        }
    }

    if (erro_encontrado || !is_empty(pilha)) {
        printf("incorrect\n");
    } else {
        printf("correct\n");
    }
    
    // Libera a memória alocada caso o loop tenha sido interrompido
    while (!is_empty(pilha)) {
        pop(&pilha);
    }
}

int main() {
    char expressao[MAX_EXPRESSAO];
    
    while (fgets(expressao, MAX_EXPRESSAO, stdin) != NULL) {
        verifica_balanco_com_lista(expressao);
    }
    
    return 0;
}
