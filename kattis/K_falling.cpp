#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    bool ok = false;
    for (int i = 1 ; i * i <= n ; i++) {
        if (n % i) continue;
        int x = i, y = n / i;
        if ((x + y) % 2) continue;
        cout << (y - x) / 2 << ' ' << (y + x) / 2 << '\n';
        ok = true; break;
    }
    if (!ok) cout << "impossible\n";
}
