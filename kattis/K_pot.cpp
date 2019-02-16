#include <bits/stdc++.h>
using namespace std;
int fpow(int a, int x) {
    if (x == 0) return 1;
    int k = fpow(a, x >> 1);
    int ret = k * k;
    if (x % 2) ret *= a;
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; int ans = 0;
    while (t--) {
        int n; cin >> n;
        ans += fpow(n / 10, n % 10);
    }
    cout << ans << '\n';
}
