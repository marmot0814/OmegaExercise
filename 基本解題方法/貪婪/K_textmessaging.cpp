#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int kase = 0;
    int t; cin >> t; while (t--) {
        cout << "Case #" << ++kase << ": ";
        LL p, k, l; cin >> p >> k >> l;
        vector<LL> data(l);
        for (auto &v : data) cin >> v;
        sort(data.begin(), data.end(), [](LL a, LL b){ return a > b; });
        vector<vector<LL> > tmp(k);
        int idx = 0;
        for (auto &v : data) {
            tmp[idx++].push_back(v);
            idx %= k;
        }
        LL ans = 0;
        for (int i = 0 ; i < k ; i++) {
            for (int j = 0 ; j < (int)tmp[i].size() ; j++)
                ans += tmp[i][j] * (j + 1);
        }
        cout << ans << '\n';
    }
}
