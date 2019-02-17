#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int x, y, c; cin >> x >> y >> c;
        if (x < y) swap(x, y);
        bool legal = false;
        if (x - y == c)
            legal = true;
        if (x + y == c)
            legal = true;
        if (x * y == c)
            legal = true;
        if (x % y == 0 && x / y == c)
            legal = true;
        if (legal)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }
}
