#include <stdio.h>
#include <stdlib.h>

void trocar(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int particionar(int arr[], int baixo, int alto) {
    int pivo = arr[alto];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++) {
        if (arr[j] <= pivo) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

void quickSort(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = particionar(arr, baixo, alto);

        quickSort(arr, baixo, pi - 1);
        quickSort(arr, pi + 1, alto);
    }
}

void imprimir_e_limpar(int arr[], int N) {
    int i;
    for (i = 0; i < N; i++) {
        printf("%d%s", arr[i], (i == N - 1) ? "" : " ");
    }
    printf("\n");
    free(arr);
}

int main() {
    int NC, N, i, j;
    
    if (scanf("%d", &NC) != 1) return 0;

    for (i = 0; i < NC; i++) {
        if (scanf("%d", &N) != 1) break;
        
        int *alturas = (int*)malloc(N * sizeof(int));
        if (alturas == NULL) return 1;

        for (j = 0; j < N; j++) {
            if (scanf("%d", &alturas[j]) != 1) break;
        }
        
        quickSort(alturas, 0, N - 1);
        
        imprimir_e_limpar(alturas, N);
    }

    return 0;
}
