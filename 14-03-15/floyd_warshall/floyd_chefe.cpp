#include "iostream"
#include "cstdio"
#include "cstring"
#include <string>
#define INF 99999999
using namespace std;

int main()
{
    int n, m, instrucoes;
    while(cin >> n >> m >> instrucoes){
        int idades[505];
        int indice[505];
        int grafo[505][505];
        memset(idades, 0, sizeof idades);
        memset(grafo, 0, sizeof grafo);
        memset(indice, 0, sizeof indice);
        int idade, pessoa1, pessoa2;
        char op;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &idade);
            idades[i] = idade;
            indice[i] = i;
        }
        for (int i = 1; i <= m; ++i)
        {
            scanf("%d %d", &pessoa1, &pessoa2);
            grafo[pessoa2][pessoa1] = 1;
        }

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (grafo[j][i] == 1)
                {
                    for (int k = 1; k <= n; ++k)
                    {
                        grafo[j][k] |= grafo[i][k];
                    }
                }
            }
        }


        for (int i = 0; i < instrucoes; ++i)
        {
            cin >> op;
            if (op == 'T')
            {
                scanf("%d %d", &pessoa1, &pessoa2);
                swap(idades[indice[pessoa1]], idades[indice[pessoa2]]);
                swap(indice[pessoa1], indice[pessoa2]);
            }
            if(op == 'P'){
                scanf("%d", &pessoa1);
                int achou = INF;
                for (int j = 1; j <= n; ++j)
                {
                    if (grafo[indice[pessoa1]][indice[j]] && idades[indice[j]] < achou)
                        {
                            achou = idades[indice[j]];
                        }    
                }
                if (achou == INF){
                    printf("*\n");
                }else{
                    printf("%d\n", achou);
                }
            }
        }

    }
    return 0;
}