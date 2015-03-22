#include <iostream>
#include <cstring>

using namespace std;

#define max(a, b) a > b ? a : b

int peso[101];
int qt[101];

int y, z;

int backpacker(int maxpeso, int index, int quantos) {
    if (index < 0 ) return 0;

    int v1 = 0, v2 = 0;

    if (maxpeso - peso[index] > 0) {
        v1 = qt[index] + backpacker(maxpeso - peso[index], index - 1, quantos+1);
    }

    v2 = backpacker(maxpeso, index - 1, 0);

    y = quantos;
    z = maxpeso;
    return max(v1, v2);
}

int main ()  {
    int n, pac;

    cin >> n;
    while(n--) {
        cin >> pac;

        memset(peso, 0, sizeof(peso));
        memset(qt, 0, sizeof(qt));

        for (int i = 0; i < pac; ++i) {
            cin  >> qt[i] >> peso[i];
        }

        cout << "oi " << backpacker(50, pac - 1, 0)<< endl << "peso" << 50 - z << endl << "qtd " << pac - y;
    }

    return 0;
}
