#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

typedef struct {
    No *frente;
    No *tras;
} Fila;

void inicializar(Fila *f) {
    f->frente = NULL;
    f->tras = NULL;
}

int estaVazia(Fila *f) {
    return (f->frente == NULL);
}

void inserir(Fila *f, int valor) {
    No *novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        return; 
    }
    novo->valor = valor;
    novo->prox = NULL;

    if (estaVazia(f)) {
        f->frente = novo;
        f->tras = novo;
    } else {
        f->tras->prox = novo;
        f->tras = novo;
    }
}

int remover(Fila *f) {
    if (estaVazia(f)) {
        return -1;
    }
    
    No *temp = f->frente;
    int valor = temp->valor;

    f->frente = f->frente->prox;

    if (f->frente == NULL) {
        f->tras = NULL;
    }
    
    free(temp);
    return valor;
}

void resolver_caso(int N) {
    if (N == 0) return;

    Fila baralho;
    inicializar(&baralho);

    for (int i = 1; i <= N; ++i) {
        inserir(&baralho, i);
    }

    int valor_descartado;
    int valor_movido;

    printf("Discarded cards: ");
    int primeiro_descarte = 1;

    while (baralho.frente != baralho.tras) {
        
        valor_descartado = remover(&baralho);
        
        if (!primeiro_descarte) {
            printf(", ");
        }
        printf("%d", valor_descartado);
        primeiro_descarte = 0;

        valor_movido = remover(&baralho);
        inserir(&baralho, valor_movido);
    }
    
    printf("\n");
    printf("Remaining card: %d\n", baralho.frente->valor);

    free(baralho.frente);
}

int main() {
    int N;
    
    while (scanf("%d", &N) == 1 && N != 0) {
        resolver_caso(N);
    }
    
    return 0;
}
