#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N_LEN 105

void resolve_caso(int D_int, char N[]) {
    
    char D_char = D_int + '0'; 
    
    char valor_filtrado[MAX_N_LEN];
    int idx_filtrado = 0; 

    for (int i = 0; N[i] != '\0'; i++) {
        if (N[i] != D_char) {
            valor_filtrado[idx_filtrado++] = N[i];
        }
    }
    valor_filtrado[idx_filtrado] = '\0'; 

    char *resultado_ptr = valor_filtrado;
    
    while (*resultado_ptr == '0' && *resultado_ptr != '\0') {
        resultado_ptr++;
    }

    if (*resultado_ptr == '\0') {
        printf("0\n");
    } else {
        printf("%s\n", resultado_ptr);
    }
}

int main() {
    int D; 
    char N[MAX_N_LEN]; 

    while (scanf("%d %s", &D, N) == 2 && (D != 0 || N[0] != '0')) {
        resolve_caso(D, N);
    }

    return 0;
}
