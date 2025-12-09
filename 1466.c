#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *left, *right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->value)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

void bfs(Node* root) {
    if (!root) return;

    Node* queue[600];
    int start = 0, end = 0;

    queue[end++] = root;

    int first = 1;

    while (start < end) {
        Node* curr = queue[start++];

        if (!first)
            printf(" ");
        printf("%d", curr->value);
        first = 0;

        if (curr->left)
            queue[end++] = curr->left;
        if (curr->right)
            queue[end++] = curr->right;
    }
}

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int C;
    scanf("%d", &C);

    for (int caseNum = 1; caseNum <= C; caseNum++) {

        int N;
        scanf("%d", &N);

        Node* root = NULL;

        for (int i = 0; i < N; i++) {
            int x;
            scanf("%d", &x);
            root = insert(root, x);
        }

        printf("Case %d:\n", caseNum);
        bfs(root);
        printf("\n\n");

        freeTree(root);
    }

    return 0;
}
