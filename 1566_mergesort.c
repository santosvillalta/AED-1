#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; 
    j = 0; 
    k = l; 

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
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
        
        mergeSort(alturas, 0, N - 1);
        imprimir_e_limpar(alturas, N);
    }

    return 0;
}
