# include <iostream>
using namespace std;
int matriz[4][4];
int n = 4;

void floyd_warshall_fecho(){
    // Calcula fecho transitivo
    // Se há um caminho de a até b e de b até c entao há um caminho de a até c
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (matriz[i][j] == 1)
            {
                for (int k = 0; k < n; ++k)
                {
                    cout << i << " " << j << " " << k << " =  " << matriz[j][k] << "  " << matriz[i][k] << endl;
                    matriz[j][k] = matriz[j][k] | matriz[i][k];
                }
            }
        }
    }
}

int floyd_warshall_menor_caminho(){
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                if (matriz[j][k] > matriz[j][i] + a[i][k])
                {
                    matriz[j][k] = matriz[j][i] + a[i][k];
                }
            }
        }
    }
}

int main(){
    matriz[0][0] = 0;
    matriz[0][1] = 1;
    matriz[0][2] = 0;
    matriz[0][3] = 0;
    matriz[1][0] = 0;
    matriz[1][1] = 0;
    matriz[1][2] = 1;
    matriz[1][3] = 0;
    matriz[2][0] = 0;
    matriz[2][1] = 0;
    matriz[2][2] = 0;
    matriz[2][3] = 1;
    matriz[3][0] = 0;
    matriz[3][1] = 0;
    matriz[3][2] = 0;
    matriz[3][3] = 0;
    floyd_warshall_fecho();
    return 0;
}