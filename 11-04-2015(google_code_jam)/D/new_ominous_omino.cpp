#include <iostream>

using namespace std;

int main()
{
    int t, x, r, c, gabriel;

    cin >> t;

    for(int i = 1; i <= t; ++i) {
        cin >> x >> r >> c;

        if ((r % x == 0 || c % x == 0) && r * c >= x * (x - 1)) {
            cout << "Case #" << i << ": GABRIEL" << endl;
        } else {
            cout << "Case #" << i << ": RICHARD" << endl;
        }

    }

    return 0;
}
