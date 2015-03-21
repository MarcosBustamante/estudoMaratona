#include <cstdio>
#include <vector>
#include <cstring>

#define MAXV 10001
#define BRANCO 0
#define CINZA 1
#define PRETO 2


using namespace std;

vector<int> grafo[MAXV];
int visitados[MAXV];


bool dfs(int v)
{
    int tam = grafo[v].size();
    for (int i = 0; i < tam; ++i) {
        if (visitados[grafo[v][i]] == PRETO)
            continue;
        if (visitados[grafo[v][i]] == CINZA)
            return true;
        visitados[grafo[v][i]] = CINZA;
        if (dfs(grafo[v][i]))
            return true;
    }

    visitados[v] = PRETO;
    return false;
}


bool temCiclo(int V)
{
    for (int i = 1; i <= V; ++i)
        if (visitados[i] == 0 && dfs(i))
            return true;
    return false;
}


int main()
{
    int T, n, m, a, b;

    scanf("%d", &T);

    for (int t = 0; t < T; ++t)
    {
        memset(visitados, BRANCO, sizeof(visitados));
        for(int i = 0; i <= 10000; ++i)
            grafo[i].clear();

        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &a, &b);
            grafo[a].push_back(b);
        }

        if (temCiclo(n))
            printf("SIM\n");
        else
            printf("NAO\n");
    }

    return 0;
}
