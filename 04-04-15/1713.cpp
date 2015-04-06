# include <cstdio>
# include <queue>
using namespace std;

int main(){
    int naves, bilhetes, inicio, fim;
    int transp[110][4];
    queue<pair<int, int> >caminho;

    while(scanf("%d %d", &naves, &bilhetes) != EOF){

        int contador = 0;
        scanf("%d %d", &inicio, &fim);
        for(int i = 1; i <= naves; ++i){
            scanf("%d %d %d %d", &transp[i][0], &transp[i][1], &transp[i][2], &transp[i][3]);
        }
        if(bilhetes > 0){
            caminho.push(make_pair(inicio, bilhetes));
        } else if(fim == inicio){
            ++contador;
        }

        while(!caminho.empty()){
            pair<int, int> d = caminho.front();
            caminho.pop();

            if(d.second != 0){
                caminho.push(make_pair(transp[d.first][0], d.second-1));
                caminho.push(make_pair(transp[d.first][1], d.second-1));
                caminho.push(make_pair(transp[d.first][2], d.second-1));
                caminho.push(make_pair(transp[d.first][3], d.second-1));
            }else{

                if(d.first == fim)
                    ++contador;
            }
        }
        printf("%d\n", contador);


    }
    return 0;
}
