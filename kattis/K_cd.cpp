#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; while (cin >> n >> m && n) {
        unordered_set<int> cnt;
        for (int i = 0 ; i < n ; i++) {
            int v; cin >> v;
            cnt.insert(v);
        }
        int ans = 0;
        for (int i = 0 ; i < m ; i++) {
            int v; cin >> v;
            ans += cnt.count(v);
        }
        cout << ans << '\n';
    }
}
