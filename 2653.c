#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 200003

unsigned long hashString(const char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash;
}

typedef struct Node {
    char *str;
    struct Node *next;
} Node;

Node* table[TABLE_SIZE];

int insert(const char *s) {
    unsigned long h = hashString(s) % TABLE_SIZE;
    Node *cur = table[h];

    while (cur) {
        if (strcmp(cur->str, s) == 0)
            return 0;
        cur = cur->next;
    }

    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->str = strdup(s);
    newNode->next = table[h];
    table[h] = newNode;

    return 1;
}

int main() {
    char buffer[1000005];
    int count = 0;

    while (fgets(buffer, sizeof(buffer), stdin)) {
        buffer[strcspn(buffer, "\n")] = '\0';

        if (insert(buffer))
            count++;
    }

    printf("%d\n", count);

    return 0;
}
