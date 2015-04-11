#include <iostream>

using namespace std;

int main()
{
    int t, x, r, c, gabriel;

    cin >> t;

    for(int i = 1; i <= t; ++i) {
        cin >> x >> r >> c;

        gabriel = 1;

        if (x == 1) {
            gabriel = 1;
        } else if (x == 2) {
            if (r % 2 != 0 && c % 2 != 0) {
                gabriel = 0;
            }
        } else if (x == 3) {
            if ((r * c) % 6 != 0) {
                gabriel = 0;
            }
            if (r == 3 && c == 3) {
                gabriel = 1;
            }
        } else if (x == 4) {
            if (r * c < 12) {
                gabriel = 0;
            }
        }

        if (gabriel) {
            cout << "Case #" << i << ": GABRIEL" << endl;
        } else {
            cout << "Case #" << i << ": RICHARD" << endl;
        }

    }

    return 0;
}
