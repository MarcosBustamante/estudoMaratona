#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>


using namespace std;

int n;
int letras[255];
int distancias[110][110];
int INF = 1 << 30;
int menor_prof = INF;
vector<pair<int, int> > caminho;


bool foi_visitado(int i, int j)
{
    return find(caminho.begin(), caminho.end(), make_pair(i, j)) != caminho.end();
}


int dfs(string matriz[], int i, int j)
{
    if (distancias[i][j] < INF)
        return distancias[i][j];

    caminho.push_back(make_pair(i, j));
    char letra = matriz[i][j];

    if (letra >= 'a' && letra <= 'z')
        letras[letra - 'a' + 'A']++;
    else
        letras[letra - 'A' + 'a']++;

    int menor_dist = INF;
    int dist;

    if (i > 0 && !letras[matriz[i-1][j]] && !foi_visitado(i-1, j) ) {
        dist = dfs(matriz, i-1, j);
        if (dist < menor_dist)
            menor_dist = dist;
    }
    if (i < n-1 && !letras[matriz[i+1][j]] && !foi_visitado(i+1, j)) {
        dist = dfs(matriz, i+1, j);
        if (dist < menor_dist)
            menor_dist = dist;
    }
    if (j > 0 && !letras[matriz[i][j-1]] && !foi_visitado(i, j-1)) {
        dist = dfs(matriz, i, j-1);
        if (dist < menor_dist)
            menor_dist = dist;
    }
    if (j < n-1 && !letras[matriz[i][j+1]] && !foi_visitado(i, j+1)) {
        dist = dfs(matriz, i, j+1);
        if (dist < menor_dist)
            menor_dist = dist;
    }

    if (letra >= 'a' && letra <= 'z')
        letras[letra - 'a' + 'A']--;
    else
        letras[letra - 'A' + 'a']--;

    caminho.pop_back();

    menor_dist++;
    if (menor_dist < distancias[i][j])
        distancias[i][j] = menor_dist;

    return distancias[i][j];
}

int main()
{
    cin >> n;
    string matriz[n];
    memset(letras, 0, sizeof letras);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            distancias[i][j] = INF;
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> matriz[i];
    }

    distancias[n-1][n-1] = 1;
    dfs(matriz, 0, 0);

    if (distancias[0][0] < INF) {
        cout << distancias[0][0] << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
