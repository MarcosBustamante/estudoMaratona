#include <cst dio>
int dimensoes, ruas;
int cidades[2000][2000];
int visitados[2000];
int menores_dist[2000];
#define INF 10000000

int inicio, fim;

void dijkstra(){
    int menor_dist, index;
    menores_dist[inicio] = 0;
    for (int i = 0; i <= ruas; ++i){
        menor_dist = INF;
        for (int j = 0; j <= dimensoes; ++j){
            if(visitados[j] == 0 && menores_dist[j] < menor_dist){
                menor_dist = menores_dist[j];
                index = j;
            }
        }
        if(menor_dist == INF)break;

        visitados[index] = 1;

        for (int j = 0; j <= dimensoes; ++j){
            if(!visitados[j] && menores_dist[j] > menor_dist + cidades[index][j]){
                menores_dist[j] = menor_dist + cidades[index][j];
            }
        }
    }
}

int main(){
    while(scanf("%d %d", &dimensoes, &ruas) && dimensoes && ruas){
        int rua_inicio, rua_fim, tempo;
        for (int i = 0; i <= dimensoes; ++i)
        {
            for (int j = 0; j <= dimensoes; ++j)
            {
                cidades[i][j] = INF;
            }
            visitados[i] = 0;
            menores_dist[i] = INF;
        }
        for (int i = 0; i < ruas; ++i)
        {
            scanf("%d %d %d", &rua_inicio, &rua_fim, &tempo);
            // printf("%d %d\n", rua_inicio, rua_fim);
            cidades[rua_inicio][rua_fim] = tempo;
        }
        scanf("%d %d", &inicio, &fim);
        dijkstra();

        for (int i = 1; i <= dimensoes; ++i){
            for (int j = 1; j <= dimensoes; ++j){
                printf("%d ", cidades[i][j]);                
            }
            printf("\n");
        }

        if(menores_dist[fim] == INF) {
            printf("-1\n");
        }
        else {
            printf("%d\n", menores_dist[fim]);
        }
    }
    return 0;
}