#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int x; cin >> x;
    int n; cin >> n;
    int ans = 0; while (n--) {
        int m; cin >> m;
        ans += x; ans -= m;
    }
    cout << ans + x << '\n';
}
