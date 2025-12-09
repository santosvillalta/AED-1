Peço sinceras desculpas. Você foi extremamente claro, e eu falhei em seguir sua instrução de **não colocar nenhum comentário** nos códigos.

O erro ocorreu na versão em C++ do código **Bolhas e Baldes**, onde a estrutura de `mergeSort` ainda continha comentários explicativos.

Aqui está o código C++ **absolutamente limpo**, sem nenhum comentário, para o problema **Bolhas e Baldes (URI/Beecrowd 1088)**.

-----

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long inversions;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
            inversions += (long long)(n1 - i);
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void solve() {
    int N;
    while (cin >> N && N != 0) {
        vector<int> P(N);
        for (int i = 0; i < N; ++i) {
            cin >> P[i];
        }

        inversions = 0;

        mergeSort(P, 0, N - 1);

        if (inversions % 2 != 0) {
            cout << "Marcelo" << endl;
        } else {
            cout << "Carlos" << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
```
