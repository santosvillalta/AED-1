#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int altura;
    int contagem;
    struct No *esquerda;
    struct No *direita;
} No;

No* criarNo(int altura) {
    No *novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        exit(EXIT_FAILURE);
    }
    novo->altura = altura;
    novo->contagem = 1;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

No* inserir(No* raiz, int altura) {
    if (raiz == NULL) {
        return criarNo(altura);
    }

    if (altura < raiz->altura) {
        raiz->esquerda = inserir(raiz->esquerda, altura);
    } else if (altura > raiz->altura) {
        raiz->direita = inserir(raiz->direita, altura);
    } else {
        raiz->contagem++;
    }
    return raiz;
}

void percorrerEImprimir(No* raiz, int *primeiro) {
    if (raiz != NULL) {
        percorrerEImprimir(raiz->esquerda, primeiro);
        
        for (int i = 0; i < raiz->contagem; i++) {
            if (!*primeiro) {
                printf(" ");
            }
            printf("%d", raiz->altura);
            *primeiro = 0;
        }

        percorrerEImprimir(raiz->direita, primeiro);
    }
}

void liberarMemoria(No* raiz) {
    if (raiz != NULL) {
        liberarMemoria(raiz->esquerda);
        liberarMemoria(raiz->direita);
        free(raiz);
    }
}

void resolve_caso(int N) {
    No *raiz = NULL;
    int altura;
    int i;

    for (i = 0; i < N; i++) {
        if (scanf("%d", &altura) != 1) break;
        raiz = inserir(raiz, altura);
    }

    int primeiro = 1;
    percorrerEImprimir(raiz, &primeiro);
    printf("\n");

    liberarMemoria(raiz);
}

int main() {
    int NC;
    int N;
    int i;
    
    if (scanf("%d", &NC) != 1) {
        return 0; 
    }

    for (i = 0; i < NC; i++) {
        
        if (scanf("%d", &N) != 1) {
            break;
        }
        
        resolve_caso(N);
    }

    return 0;
}
