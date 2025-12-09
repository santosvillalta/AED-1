#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int LOG = 17;

int N;
vector<pair<int,long long>> g[MAXN];
int up[MAXN][LOG];
int depth[MAXN];
long long dist[MAXN];

void dfs(int u, int p) {
    up[u][0] = p;
    for(int i=1;i<LOG;i++)
        up[u][i] = up[ up[u][i-1] ][i-1];

    for(auto &e : g[u]){
        int v = e.first;
        long long w = e.second;
        if(v==p) continue;
        depth[v] = depth[u]+1;
        dist[v] = dist[u]+w;
        dfs(v,u);
    }
}

int LCA(int u,int v){
    if(depth[u]<depth[v]) swap(u,v);

    for(int i=LOG-1;i>=0;i--)
        if(depth[u]-(1<<i)>=depth[v])
            u = up[u][i];
    
    if(u==v) return u;

    for(int i=LOG-1;i>=0;i--){
        if(up[u][i]!=up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(cin >> N && N){
        for(int i=0;i<N;i++) g[i].clear();

        for(int i=1;i<N;i++){
            int Ai; long long Li;
            cin >> Ai >> Li;
            g[i].push_back({Ai,Li});
            g[Ai].push_back({i,Li});
        }

        depth[0]=0;
        dist[0]=0;
        dfs(0,0);

        int Q; cin >> Q;
        for(int i=0;i<Q;i++){
            int S,T; cin >> S >> T;
            int lca = LCA(S,T);
            long long ans = dist[S]+dist[T]-2*dist[lca];
            if(i>0) cout << " ";
            cout << ans;
        }
        cout << "\n";
    }
}
