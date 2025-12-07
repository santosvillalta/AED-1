#include <stdio.h>

int rev(int x){
    int r = 0;
    while(x > 0){
        r = r*10 + (x%10);
        x /= 10;
    }
    return r;
}

int q[20000];

int main() {
    int T;
    scanf("%d", &T);
    while(T--){
        int A, B;
        scanf("%d %d", &A, &B);

        int dist[10000];
        for(int i=0;i<10000;i++) dist[i] = -1;

        int h = 0, t = 0;
        q[t++] = A;
        dist[A] = 0;

        while(h < t){
            int u = q[h++];
            if(u == B) break;

            int v1 = u + 1;
            if(v1 < 10000 && dist[v1] == -1){
                dist[v1] = dist[u] + 1;
                q[t++] = v1;
            }

            int v2 = rev(u);
            if(v2 < 10000 && dist[v2] == -1){
                dist[v2] = dist[u] + 1;
                q[t++] = v2;
            }
        }

        printf("%d\n", dist[B]);
    }
    return 0;
}
