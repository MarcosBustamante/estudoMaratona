#include <iostream>
#include <cstring>
#include <queue>

#define MAX 20

using namespace std;

struct salao {
    int l;
    int c;
    int p;
    salao(int l, int c, int p): l(l), c(c), p(p){}
};

int grafo[MAX][MAX];


salao* bfs(int n, int m, salao* inicio)
{
    queue<salao* > fila;
    salao* atual;

    fila.push(inicio);

    while(!fila.empty())
    {
        atual = fila.front();
        fila.pop();

        if (grafo[atual->l][atual->c] == 0)
            return atual;

        grafo[atual->l][atual->c] = 2; // visitado

        if ( atual->l > 0 && grafo[atual->l-1][atual->c] < 2 ) {
            fila.push(new salao(atual->l-1, atual->c, atual->p + 1));
        }

        if ( atual->l < n-1 && grafo[atual->l+1][atual->c] < 2 ) {
            fila.push(new salao(atual->l+1, atual->c, atual->p + 1));
        }

        if ( atual->c > 0 && grafo[atual->l][atual->c-1] < 2) {
            fila.push(new salao(atual->l, atual->c-1, atual->p + 1));
        }

        if ( atual->c < m-1 && grafo[atual->l][atual->c+1] < 2) {
            fila.push(new salao(atual->l, atual->c+1, atual->p + 1));
        }
    }

}


int main()
{
    memset(grafo, 0, sizeof(grafo));
    int n, m;
    salao* inicio;

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> grafo[i][j];

            if (grafo[i][j] == 3)
                inicio = new salao(i, j, 0);
        }
    }

    cout << bfs(n, m, inicio)->p << endl;

    return 0;
}