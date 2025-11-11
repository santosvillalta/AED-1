#include <stdio.h>
#include <stdlib.h>

#define ALTURA_MIN 20
#define ALTURA_MAX 230
#define TAMANHO_CONTAGEM (ALTURA_MAX + 1)

void resolve_caso(int N) {
    int contagem[TAMANHO_CONTAGEM] = {0};
    int i, altura;

    for (i = 0; i < N; i++) {
        if (scanf("%d", &altura) != 1) {
            break;
        }
        contagem[altura]++;
    }

    int primeiro = 1; 
    
    for (altura = ALTURA_MIN; altura <= ALTURA_MAX; altura++) {
        
        for (i = 0; i < contagem[altura]; i++) {
            
            if (!primeiro) {
                printf(" ");
            }
            printf("%d", altura);
            primeiro = 0;
        }
    }
    printf("\n");
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
