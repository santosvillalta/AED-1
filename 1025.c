#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N, Q, x, i, caso = 1;

    while (1) {
        scanf("%d %d", &N, &Q);
        if (N == 0 && Q == 0) break;

        int marbles[N];

        for (i = 0; i < N; i++)
            scanf("%d", &marbles[i]);

        // Ordena os mármores
        qsort(marbles, N, sizeof(int), cmp);

        printf("CASE# %d:\n", caso++);

        // Processa as consultas
        while (Q--) {
            scanf("%d", &x);

            // Busca binária manual para encontrar a primeira posição de x
            int left = 0, right = N - 1, mid, pos = -1;

            while (left <= right) {
                mid = (left + right) / 2;

                if (marbles[mid] == x) {
                    pos = mid;     // achou
                    right = mid - 1;  // mas continua procurando o primeiro
                }
                else if (marbles[mid] < x) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }

            if (pos == -1)
                printf("%d not found\n", x);
            else
                printf("%d found at %d\n", x, pos + 1);
        }
    }

    return 0;
}
