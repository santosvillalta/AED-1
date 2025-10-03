#include <stdio.h>
#include <string.h>

#define MAX_EXPRESSAO 1005

void verifica_balanco_sem_ponteiros(const char expressao[]) {
    int contador_balanco = 0; 
    int erro_encontrado = 0;
    
    for (int i = 0; expressao[i] != '\0'; i++) {
        
        char c = expressao[i];

        if (c == '(') {
            contador_balanco++;
        } 
        else if (c == ')') {
            contador_balanco--;
        }

        if (contador_balanco < 0) {
            erro_encontrado = 1;
            break;
        }
    }

    if (erro_encontrado || contador_balanco != 0) {
        printf("incorrect\n");
    } else {
        printf("correct\n");
    }
}

int main() {
    char expressao[MAX_EXPRESSAO];
    
    while (fgets(expressao, MAX_EXPRESSAO, stdin) != NULL) {
        verifica_balanco_sem_ponteiros(expressao);
    }
    
    return 0;
}
