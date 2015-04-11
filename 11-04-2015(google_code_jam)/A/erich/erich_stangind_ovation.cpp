#include<iostream>
#include<vector>
#include<string>
using namespace std;

int toInt(char c){
    return c - '0';
}
int main(){
    int t, smax, digito_atual, diferenca;
    string sdigits;
    vector<int>digitos;
    cin >> t;
    for(int i = 1; i <= t; i++){
        int soma = 0;
        digitos.clear();
        cin >> smax >> sdigits;

        digitos.push_back(toInt(sdigits[0]));
        for(int j = 1; j <= smax; j++){
            digito_atual = toInt(sdigits[j]);

            if(digitos[j-1] >= j){
                digitos.push_back(digitos[j-1] + digito_atual);
            }else{
                diferenca = j - digitos[j-1];
                soma += diferenca;
                digitos.push_back(digito_atual + j);
            }
        }
        cout << "Case #" << i << ": " << soma << endl;
    }
}
