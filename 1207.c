#include <stdio.h>

int main() {
    int N, M;
    while(scanf("%d %d", &N, &M) == 2){
        int C[601];
        for(int i=1;i<=N;i++) scanf("%d", &C[i]);

        int P[401];
        for(int i=1;i<=M;i++) scanf("%d", &P[i]);

        int B[401];
        int cat[401][601];
        for(int i=1;i<=M;i++){
            scanf("%d", &B[i]);
            for(int j=0;j<P[i];j++){
                scanf("%d", &cat[i][j]);
            }
        }

        // Estratégia simplificada: tentar comprar todas as vodkas
        int sum_c=0;
        for(int i=1;i<=N;i++) sum_c += C[i];

        int sum_b=0;
        for(int i=1;i<=M;i++){
            int valid = 1;
            for(int j=0;j<P[i];j++){
                int v = cat[i][j];
                // todas as vodkas compradas
                // aqui estamos comprando todas
                if(v<1 || v>N) { valid=0; break; }
            }
            if(valid) sum_b += B[i];
        }

        printf("%d\n", sum_b - sum_c);
    }
    return 0;
}
