#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pLL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int kase = 0;
    int t; cin >> t; while (t--) {
        cout << "Case " << ++kase << ": ";
        int n; cin >> n;
        vector<pLL> data(n);
        for (int i = 0 ; i < n;  i++) {
            LL a, b; cin >> a >> b;
            data.push_back({-b, -a});
        }
        sort(data.begin(), data.end());
        LL maxV = 0, res = 0, minV = INF;
        for (int i = 0 ; i < n ; i++) {
            minV = min(minV, -data[i].first);
            res += -data[i].second;
            maxV = max(maxV, res * minV);
        }
        cout << maxV << '\n';
    }
}
