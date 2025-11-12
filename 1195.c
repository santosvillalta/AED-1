#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;

No* criarNo(int valor) {
    No *novo = new No();
    if (novo == NULL) {
        exit(EXIT_FAILURE); 
    }
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else { 
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

void liberarMemoria(No* raiz) {
    if (raiz != NULL) {
        liberarMemoria(raiz->esquerda);
        liberarMemoria(raiz->direita);
        delete raiz;
    }
}

void pre_ordem(No* raiz, vector<int>& resultado) {
    if (raiz != NULL) {
        resultado.push_back(raiz->valor);
        pre_ordem(raiz->esquerda, resultado);
        pre_ordem(raiz->direita, resultado);
    }
}

void in_ordem(No* raiz, vector<int>& resultado) {
    if (raiz != NULL) {
        in_ordem(raiz->esquerda, resultado);
        resultado.push_back(raiz->valor);
        in_ordem(raiz->direita, resultado);
    }
}

void post_ordem(No* raiz, vector<int>& resultado) {
    if (raiz != NULL) {
        post_ordem(raiz->esquerda, resultado);
        post_ordem(raiz->direita, resultado);
        resultado.push_back(raiz->valor);
    }
}

void imprimir_resultado(const string& prefixo, const vector<int>& resultado) {
    cout << prefixo << ":";
    for (size_t i = 0; i < resultado.size(); ++i) {
        cout << " " << resultado[i];
    }
    cout << endl;
}

void solve() {
    int C;
    if (!(cin >> C)) return;

    for (int n_caso = 1; n_caso <= C; ++n_caso) {
        int N;
        if (!(cin >> N)) break;

        No* raiz = NULL;
        int valor;

        for (int i = 0; i < N; ++i) {
            if (!(cin >> valor)) break;
            raiz = inserir(raiz, valor);
        }

        vector<int> pre_res, in_res, post_res;

        pre_ordem(raiz, pre_res);
        in_ordem(raiz, in_res);
        post_ordem(raiz, post_res);

        cout << "Case " << n_caso << ":" << endl;
        
        imprimir_resultado("Pre.", pre_res);
        imprimir_resultado("In..", in_res);
        imprimir_resultado("Post", post_res);

        if (n_caso < C) {
            cout << endl;
        }

        liberarMemoria(raiz);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
