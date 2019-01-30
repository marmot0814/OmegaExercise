#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; while (cin >> n && n) {
        cin >> m;
        vector<int> data[2];
        for (int i = 0 ; i < n ; i++) {
            int v; cin >> v; data[0].push_back(v);
        }
        for (int i = 0 ; i < m ; i++) {
            int v; cin >> v; data[1].push_back(v);
        }
        vector<double> ans;
        for (auto &v : data[0])
            for (auto &vv : data[1])
                ans.push_back((double)v / vv);
        double maxV = 0;
        sort(ans.begin(), ans.end());
        for (int i = 0 ; i < (int)ans.size() - 1 ; i++)
            maxV = max(maxV, ans[i + 1] / ans[i]);
        cout << fixed << setprecision(2) << maxV << '\n';
    }
}
