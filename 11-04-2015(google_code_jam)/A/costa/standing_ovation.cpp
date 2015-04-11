#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

stringstream stream;
int toInt(const char c) {
    return c - '0';
}

int main()
{
    int T, smax, n, friends, diff;
    string people;
    vector<int> quantidades;

    cin >> T;

    for (int c = 1; c <= T; ++c) {
        quantidades.clear();
        friends = 0;

        cin >> smax >> people;

        quantidades.push_back(toInt(people[0]));

        for (int i = 1; i <= smax; ++i) {
            n = toInt(people[i]);

            diff = quantidades[i-1] < i ? i - quantidades[i-1] : 0;

            if (diff) {
                friends += diff;
            }

            quantidades.push_back(quantidades[i-1] + n + diff);
        }
        cout << "Case #" << c << ": " << friends << endl;
    }

    return 0;
}
