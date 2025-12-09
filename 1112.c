#include <stdio.h>
#include <string.h>

#define MAX 1005

int BIT[MAX][MAX];
int X, Y, PRECO;

void update(int x, int y, int val) {
    int yy;
    while (x <= X) {
        yy = y;
        while (yy <= Y) {
            BIT[x][yy] += val;
            yy += (yy & -yy);
        }
        x += (x & -x);
    }
}

int query(int x, int y) {
    int sum = 0, yy;
    while (x > 0) {
        yy = y;
        while (yy > 0) {
            sum += BIT[x][yy];
            yy -= (yy & -yy);
        }
        x -= (x & -x);
    }
    return sum;
}

int queryRect(int x1, int y1, int x2, int y2) {
    return  query(x2, y2)
          - query(x1 - 1, y2)
          - query(x2, y1 - 1)
          + query(x1 - 1, y1 - 1);
}

int main() {
    while (1) {
        scanf("%d %d %d", &X, &Y, &PRECO);
        if (X == 0 && Y == 0 && PRECO == 0)
            break;

        memset(BIT, 0, sizeof(BIT));

        int Q;
        scanf("%d", &Q);

        while (Q--) {
            char op;
            scanf(" %c", &op);

            if (op == 'A') {
                int N, x, y;
                scanf("%d %d %d", &N, &x, &y);
                update(x + 1, y + 1, N);
            } 
            else { // op == 'P'
                int x1, y1, x2, y2;
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

                // normalizar pois o retângulo pode vir invertido
                int lx = (x1 < x2 ? x1 : x2);
                int hx = (x1 > x2 ? x1 : x2);
                int ly = (y1 < y2 ? y1 : y2);
                int hy = (y1 > y2 ? y1 : y2);

                int total = queryRect(lx + 1, ly + 1, hx + 1, hy + 1);

                printf("%d\n", total * PRECO);
            }
        }

        printf("\n");
    }

    return 0;
}
