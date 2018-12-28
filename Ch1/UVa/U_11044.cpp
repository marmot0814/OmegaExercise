#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n, m; cin >> n >> m;
        n -= 3; m -= 3;
        cout << (n / 3 + 1) * (m  / 3 + 1) << '\n';
    }
}
