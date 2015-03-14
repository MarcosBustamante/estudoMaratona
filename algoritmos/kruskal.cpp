# include <cstdio>
# include <cstring>
# include <vector>
# include <algorithm>

using namespace std;

# define pii pair<int, int>
# define pip pair<int, pii>
# define S second
# define F first

int grafo[200];
vector<pip>vet;
vector<pii>salvar;
int casas, fios;


int union_find(int x){
    while(grafo[x])
        x = grafo[x];
    return x;
}

void insert(int x, int y){
    grafo[min(x, y)] = max(x, y);
}

void kruskal(){
    int count = 0, n1, n2;
    for (int i = 0; i < vet.size(); ++i)
    {
        n1 = union_find(vet[i].S.F);
        n2 = union_find(vet[i].S.S);
        if(n1 != n2){
            insert(n1, n2);
            salvar.push_back(vet[i].S);
            ++count;
        }
        if (count == casas - 1) break;
    }
}

int main(){
    int c1, c2, p, I =0;

    while(scanf("%d %d", &casas, &fios) && casas + fios){
        vet.clear();
        salvar.clear();
        memset(grafo, 0, sizeof(grafo));

        for (int i = 0; i < fios; ++i) {
            scanf("%d %d %d", &c1, &c2, &p);
            vet.push_back( pip( p, pii( min(c1, c2), max(c1, c2) ) ) );
        }

        sort(vet.begin(), vet.end());

        kruskal();
        printf("Teste %d\n", ++I);

        for (int i = 0; i < salvar.size(); ++i)
        {
            printf("%d %d\n", salvar[i].F, salvar[i].S);
        }
        printf("\n");
    }
}