```cpp
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N)) return;

    vector<int> fila_inicial(N);
    for (int i = 0; i < N; ++i) {
        if (!(cin >> fila_inicial[i])) return;
    }

    int M;
    if (!(cin >> M)) return;

    unordered_set<int> saiu;
    for (int i = 0; i < M; ++i) {
        int id_saida;
        if (!(cin >> id_saida)) return;
        saiu.insert(id_saida);
    }

    bool primeiro = true;

    for (int id_pessoa : fila_inicial) {
        
        if (saiu.find(id_pessoa) == saiu.end()) {
            
            if (!primeiro) {
                cout << " ";
            }
            cout << id_pessoa;
            primeiro = false;
        }
    }
    cout << "\n";
}

int main() {
    solve();
    return 0;
}
```
