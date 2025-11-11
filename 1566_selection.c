#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
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
        
        selectionSort(alturas, N);
        imprimir_e_limpar(alturas, N);
    }

    return 0;
}
