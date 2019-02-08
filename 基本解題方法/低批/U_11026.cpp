#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    LL n, m; while (cin >> n >> m && n) {
        vector<LL> ans{1};
        for (int x = 0 ; x < n ; x++) {
            LL v; cin >> v;
            vector<LL> pat{v, 1}, res(ans.size() + 1, 0);
            for (int i = 0 ; i < (int)ans.size() ; i++)
                for (int j = 0 ; j < 2 ; j++)
                    res[i + j] += ans[i] * pat[j], res[i + j] %= m;
            ans = res;
        }
        LL maxV = 0;
        for (auto &v : ans)
            maxV = max(maxV, abs(v) % m);
        cout << maxV << '\n';
    }
}
