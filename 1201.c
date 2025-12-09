#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int val;
    struct node *left, *right;
} Node;

// Inserção na BST
Node* insert(Node* root, int v) {
    if (!root) {
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

// Busca
int search(Node* root, int v) {
    if (!root) return 0;
    if (v == root->val) return 1;
    if (v < root->val) return search(root->left, v);
    return search(root->right, v);
}

// Percursos
void printIn(Node* root, int *first) {
    if (!root) return;
    printIn(root->left, first);
    if (!(*first)) printf(" ");
    printf("%d", root->val);
    *first = 0;
    printIn(root->right, first);
}

void printPre(Node* root, int *first) {
    if (!root) return;
    if (!(*first)) printf(" ");
    printf("%d", root->val);
    *first = 0;
    printPre(root->left, first);
    printPre(root->right, first);
}

void printPos(Node* root, int *first) {
    if (!root) return;
    printPos(root->left, first);
    printPos(root->right, first);
    if (!(*first)) printf(" ");
    printf("%d", root->val);
    *first = 0;
}

// Remoção
Node* removeNode(Node* root, int v) {
    if (!root) return NULL;
    if (v < root->val) root->left = removeNode(root->left, v);
    else if (v > root->val) root->right = removeNode(root->right, v);
    else {
        // Caso com 0 ou 1 filho
        if (!root->left) {
            Node* tmp = root->right;
            free(root);
            return tmp;
        } else if (!root->right) {
            Node* tmp = root->left;
            free(root);
            return tmp;
        }
        // Caso 2 filhos: antecessor (maior da esquerda)
        Node* tmp = root->left;
        while (tmp->right) tmp = tmp->right;
        root->val = tmp->val;
        root->left = removeNode(root->left, tmp->val);
    }
    return root;
}

int main() {
    Node* root = NULL;
    char cmd[20];

    while (scanf("%s", cmd) != EOF) {
        if (strcmp(cmd, "I") == 0) {
            int n; scanf("%d", &n);
            root = insert(root, n);
        } 
        else if (strcmp(cmd, "R") == 0) {
            int n; scanf("%d", &n);
            root = removeNode(root, n);
        } 
        else if (strcmp(cmd, "P") == 0) {
            int n; scanf("%d", &n);
            if (search(root, n))
                printf("%d existe\n", n);
            else
                printf("%d nao existe\n", n);
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
