#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

int main() {
    int N;
    scanf("%d", &N);

    for (int t = 0; t < N; t++) {
        int M, C;
        scanf("%d %d", &M, &C);

        Node *table[101];
        for (int i = 0; i < M; i++)
            table[i] = NULL;

        for (int i = 0; i < C; i++) {
            int x;
            scanf("%d", &x);
            int h = x % M;

            Node *n = (Node*) malloc(sizeof(Node));
            n->value = x;
            n->next = NULL;

            if (table[h] == NULL) {
                table[h] = n;
            } else {
                Node *cur = table[h];
                while (cur->next != NULL)
                    cur = cur->next;
                cur->next = n;
            }
        }

        for (int i = 0; i < M; i++) {
            printf("%d -> ", i);
            Node *cur = table[i];
            while (cur) {
                printf("%d -> ", cur->value);
                cur = cur->next;
            }
            printf("\\\n");
        }

        if (t < N - 1)
            printf("\n");
    }

    return 0;
}
