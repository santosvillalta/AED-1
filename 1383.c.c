#include <stdio.h>
#include <stdlib.h>

#define N 9

int** alocar_t()
{
    int** t = (int**) malloc(N * sizeof(int*));
    if (t == NULL) { exit(1); }
    for (int i = 0; i < N; i++) {
        t[i] = (int*) malloc(N * sizeof(int));
        if (t[i] == NULL) {
            for (int j = 0; j < i; j++) { free(t[j]); }
            free(t);
            exit(1);
        }
    }
    return t;
}

void liberar_t(int** t)
{
    for (int i = 0; i < N; i++) { free(t[i]); }
    free(t);
}

int v_l(int** t, int l)
{
    int n[N + 1] = {0};
    for (int c = 0; c < N; c++) {
        int num = t[l][c];
        if (num < 1 || num > 9 || n[num] == 1) { return 0; }
        n[num] = 1;
    }
    return 1;
}

int v_c(int** t, int c)
{
    int n[N + 1] = {0};
    for (int l = 0; l < N; l++) {
        int num = t[l][c];
        if (num < 1 || num > 9 || n[num] == 1) { return 0; }
        n[num] = 1;
    }
    return 1;
}

int v_b(int** t, int il, int ic)
{
    int n[N + 1] = {0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int num = t[i + il][j + ic];
            if (num < 1 || num > 9 || n[num] == 1) { return 0; }
            n[num] = 1;
        }
    }
    return 1;
}

int eh_sol(int** t)
{
    for (int i = 0; i < N; i++) {
        if (!v_l(t, i) || !v_c(t, i)) { return 0; }
    }
    for (int i = 0; i < N; i += 3) {
        for (int j = 0; j < N; j += 3) {
            if (!v_b(t, i, j)) { return 0; }
        }
    }
    return 1;
}

int main()
{
    int n, k, i, j;
    int** t;
    scanf("%d", &n);
    for (k = 1; k <= n; k++) {
        t = alocar_t();
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                scanf("%d", &t[i][j]);
            }
        }
        printf("Instancia %d\n", k);
        if (eh_sol(t)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n");
        liberar_t(t);
    }
    return 0;
}
