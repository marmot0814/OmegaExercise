#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, y; cin >> x >> y;
    if (x == 0 && y == 0) {
        cout << "Not a moose\n";
    } else {
        if (x == y) {
            cout << "Even " << 2 * x << '\n';
        } else {
            cout << "Odd " << 2 * max(x, y) << '\n';
        }
    }
}

