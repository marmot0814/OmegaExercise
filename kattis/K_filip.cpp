#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int x, y; cin >> x >> y;
    int a = 0, b = 0;
    while (x)
        a *= 10, a += x % 10, x /= 10;
    while (y)
        b *= 10, b += y % 10, y /= 10;
    cout << max(a, b) << '\n';
}

