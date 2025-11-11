#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n) {
    int i, chave, j;
    for (i = 1; i < n; i++) {
        chave = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave;
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
        
        insertionSort(alturas, N);
        imprimir_e_limpar(alturas, N);
    }

    return 0;
}
