#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int indice = 1;
    int metade = n / 2;
    int contador = 0;


    do {

        if (indice <= metade) {
            indice *= 2;
        } else {
            indice = (indice * 2 - 1) % n;
        }

        ++contador;
    } while(indice != 1);

    cout << contador << endl;

    return 0;
}

