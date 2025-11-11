#include <stdio.h>
#include <stdlib.h>

void heapify(int arr[], int n, int i) {
    int maior = i; 
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < n && arr[esquerda] > arr[maior]) {
        maior = esquerda;
    }

    if (direita < n && arr[direita] > arr[maior]) {
        maior = direita;
    }

    if (maior != i) {
        int temp = arr[i];
        arr[i] = arr[maior];
        arr[maior] = temp;

        heapify(arr, n, maior);
    }
}

void heapSort(int arr[], int n) {
    int i;
    
    for (i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
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
        
        heapSort(alturas, N);
        imprimir_e_limpar(alturas, N);
    }

    return 0;
}
