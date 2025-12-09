#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char val;
    struct node *left, *right;
} Node;

Node* insert(Node* root, char v) {
    if (root == NULL) {
        Node* n = (Node*) malloc(sizeof(Node));
        n->val = v;
        n->left = n->right = NULL;
        return n;
    }
    if (v < root->val)
        root->left = insert(root->left, v);
    else if (v > root->val)
        root->right = insert(root->right, v);
    return root;
}

int search(Node* root, char v) {
    if (root == NULL) return 0;
    if (v == root->val) return 1;
    if (v < root->val) return search(root->left, v);
    return search(root->right, v);
}

void printIn(Node* root, int *first) {
    if (root == NULL) return;
    printIn(root->left, first);
    if (!(*first)) printf(" ");
    printf("%c", root->val);
    *first = 0;
    printIn(root->right, first);
}

void printPre(Node* root, int *first) {
    if (root == NULL) return;
    if (!(*first)) printf(" ");
    printf("%c", root->val);
    *first = 0;
    printPre(root->left, first);
    printPre(root->right, first);
}

void printPos(Node* root, int *first) {
    if (root == NULL) return;
    printPos(root->left, first);
    printPos(root->right, first);
    if (!(*first)) printf(" ");
    printf("%c", root->val);
    *first = 0;
}

int main() {
    Node* root = NULL;
    char cmd[20];

    while (scanf("%s", cmd) != EOF) {

        if (strcmp(cmd, "I") == 0) {
            char c;
            scanf(" %c", &c);
            root = insert(root, c);
        }

        else if (strcmp(cmd, "P") == 0) {
            char c;
            scanf(" %c", &c);
            if (search(root, c))
                printf("%c existe\n", c);
            else
                printf("%c nao existe\n", c);
        }

        else if (strcmp(cmd, "INFIXA") == 0) {
            int first = 1;
            printIn(root, &first);
            printf("\n");
        }

        else if (strcmp(cmd, "PREFIXA") == 0) {
            int first = 1;
            printPre(root, &first);
            printf("\n");
        }

        else if (strcmp(cmd, "POSFIXA") == 0) {
            int first = 1;
            printPos(root, &first);
            printf("\n");
        }
    }

    return 0;
}
