#include <stdio.h>

#define N 9

int v_l(int t[N][N], int l) {
    int n[N + 1] = {0};
    for (int c = 0; c < N; c++) {
        int num = t[l][c];
        if (num < 1 || num > 9 || n[num] == 1) {
            return 0;
        }
        n[num] = 1;
    }
    return 1;
}

int v_c(int t[N][N], int c) {
    int n[N + 1] = {0};
    for (int l = 0; l < N; l++) {
        int num = t[l][c];
        if (num < 1 || num > 9 || n[num] == 1) {
            return 0;
        }
        n[num] = 1;
    }
    return 1;
}

int v_b(int t[N][N], int il, int ic) {
    int n[N + 1] = {0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int num = t[i + il][j + ic];
            if (num < 1 || num > 9 || n[num] == 1) {
                return 0;
            }
            n[num] = 1;
        }
    }
    return 1;
}

int eh_solucao(int t[N][N]) {
    for (int i = 0; i < N; i++) {
        if (!v_l(t, i) || !v_c(t, i)) {
            return 0;
        }
    }
    for (int i = 0; i < N; i += 3) {
        for (int j = 0; j < N; j += 3) {
            if (!v_b(t, i, j)) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int n, k, i, j;
    int t[N][N];

    scanf("%d", &n);

    for (k = 1; k <= n; k++) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                scanf("%d", &t[i][j]);
            }
        }

        printf("Instancia %d\n", k);
        if (eh_solucao(t)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n");
    }

    return 0;
}
