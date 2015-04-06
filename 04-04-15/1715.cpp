#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int n, m, saida, aux;
    cin >> n >> m;

    int pessoas[n+1];
    memset(pessoas, 0, sizeof pessoas);
    saida = n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> aux;
            if(!pessoas[i] && aux == 0){
                pessoas[i] = 1;
                saida--;
            }
        }
    }

    cout << saida << endl;
    return 0;
}
