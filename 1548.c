#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void resolve_caso() {
    int M;
    if (!(cin >> M)) return;

    vector<int> notas_chegada(M);
    vector<int> notas_ordenadas(M);

    for (int i = 0; i < M; ++i) {
        if (!(cin >> notas_chegada[i])) return;
        notas_ordenadas[i] = notas_chegada[i];
    }

    sort(notas_ordenadas.begin(), notas_ordenadas.end(), greater<int>());

    int alunos_nao_trocaram = 0;

    for (int i = 0; i < M; ++i) {
        if (notas_chegada[i] == notas_ordenadas[i]) {
            alunos_nao_trocaram++;
        }
    }

    cout << alunos_nao_trocaram << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    for (int i = 0; i < N; ++i) {
        resolve_caso();
    }

    return 0;
}
