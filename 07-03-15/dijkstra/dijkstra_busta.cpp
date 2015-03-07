#include <cstdio>
#define INF 1000000
int dimen, ruas, inicio, fim;

int cidade[2000][2000];
int visitados[2000];
int menores_dist[2000];

void dijkstra(){
    menores_dist[inicio] = 0;
    int menor_dist, index;
    for(int i = 0; i < ruas; ++i){
        menor_dist = INF;
        for (int j = 0; j <= dimen; ++j){
            if(menores_dist[j] < menor_dist && visitados[j] == 0){
                menor_dist = menores_dist[j];
                index = j;
            }
        }

        if(menor_dist == INF) break;
        visitados[index] = 1;

        for (int j = 0; j <= dimen; ++j){
            if(visitados[j] == 0 && cidade[index][j] + menor_dist < menores_dist[j]){
                menores_dist[j] = cidade[index][j] + menor_dist;
            }
        }
    }
}

int main(){
    while(scanf("%d %d", &dimen, &ruas) && dimen && ruas){
        for(int i = 0; i <= dimen; ++i){
            for(int j = 0; j <= dimen; ++j){
                cidade[i][j] = INF;
            }
            menores_dist[i] = INF;
            visitados[i] = 0;
        }

        int rua_inicio, rua_destino, tempo;
        for(int i = 0; i < ruas; ++i){
            scanf("%d %d %d", &rua_inicio, &rua_destino, &tempo);
            cidade[rua_inicio][rua_destino] = tempo;
        }

        scanf("%d %d", &inicio, &fim);

        dijkstra();

        if(menores_dist[fim] == INF){
            printf("-1\n");
        } else {
            printf("%d\n", menores_dist[fim]);
        }
    }
}
