#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, y; while (cin >> x >> y && (x || y)) {
        if (x + y == 13) {
            cout << "Never speak again.\n";
            continue;
        }
        if (x > y) {
            cout << "To the convention.\n";
            continue;
        }
        if (x < y) {
            cout << "Left beehind.\n";
            continue;
        }
        if (x == y) {
            cout << "Undecided.\n";
            continue;
        }
    }
}

