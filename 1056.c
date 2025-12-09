#include <stdio.h>
#include <string.h>

int n, m;
int A[105], B[105];
int match[105];
int vis[105];

int dfs(int u) {
    int v;
    for (v = 0; v < m; v++) {
        int is_multiple = 0;
        if (A[u] == 0) {
            if (B[v] == 0) is_multiple = 1;
        } else {
            if (B[v] % A[u] == 0) is_multiple = 1;
        }

        if (is_multiple && !vis[v]) {
            vis[v] = 1;
            if (match[v] < 0 || dfs(match[v])) {
                match[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int t, case_num = 1;
    if (scanf("%d", &t) != 1) return 0;

    while (t--) {
        int i;
        scanf("%d", &n);
        for (i = 0; i < n; i++) scanf("%d", &A[i]);
        
        scanf("%d", &m);
        for (i = 0; i < m; i++) scanf("%d", &B[i]);

        memset(match, -1, sizeof(match));
        int result = 0;
        
        for (i = 0; i < n; i++) {
            memset(vis, 0, sizeof(vis));
            if (dfs(i)) result++;
        }

        printf("Case %d: %d\n", case_num++, result);
    }
    return 0;
}
