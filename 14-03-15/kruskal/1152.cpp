#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define pii pair<int, int>
#define pip pair<int, pii>

using namespace std;

int grafo[300000];
vector<pip> conjuntos, saida;


int union_find(int x)
{
    while(grafo[x])
        x = grafo[x];
    return x;
}

void insert(int x, int y)
{
    grafo[x] = y;
}

int kruskal(int n, int m)
{
    int counter = 0, total = 0, x, y;

    sort(conjuntos.begin(), conjuntos.end());

    for (int i = 0; i < m; ++i) {
        x = union_find(conjuntos[i].second.first);
        y = union_find(conjuntos[i].second.second);

        if (x != y) {
            total += conjuntos[i].first;
            insert(x, y);
            ++counter;
        }
        if (counter == m-1) break;
    }

    return total;
}


int main()
{
    int n, m, x, y, z, total;

    while ((cin >> m >> n) && n && m)
    {
        conjuntos.clear();
        saida.clear();
        memset(grafo, 0, sizeof(grafo));
        total = 0;

        for (int i = 0; i < n; ++i) {
            cin >> x >> y >> z;
            conjuntos.push_back(pip(z, pii(x, y)));
            total += z;
        }

        cout << (total - kruskal(m, n)) << endl;
    }

    return 0;
}
