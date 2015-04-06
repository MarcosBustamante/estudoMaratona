#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a,b;
    cin >> a >> b;
    cout << ceil(b / (b - a)) << endl;
    return 0;
}
