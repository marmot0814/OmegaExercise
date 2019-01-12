#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        LL ans = 0;
        for (int i = 0 ; i < n ; i++) {
            LL x, y, z; cin >> x >> y >> z;
            ans += x * z;
        }
        cout << ans << '\n';
    }
}
