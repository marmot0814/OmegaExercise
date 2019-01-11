#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int kase = 0;
    int t; cin >> t; while (t--) {
        int n, ans = 0; cin >> n;
        for (int i = 0 ; i < n ; i++) {
            int num; cin >> num;
            ans = max(ans, num);
        }
        cout << "Case " << ++kase << ": " << ans << '\n';
    }
}
