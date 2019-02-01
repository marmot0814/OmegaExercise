#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n) {
        vector<int> data(n);
        for (auto &v : data) cin >> v;
        vector<int> LIS; vector<vector<pii> > ans;
        for (int i = 0 ; i < (int)data.size() ; i++) {
            int v = data[i];
            int p = lower_bound(LIS.begin(), LIS.end(), v) - LIS.begin();
            if (p == (int)LIS.size()) {
                LIS.push_back(v);
                if (p == 0) {
                    ans.push_back(vector<pii>{{i, -1}});
                } else {
                    ans.push_back(vector<pii>{{i, ans[p - 1].size() - 1}});
                }
            } else {
                LIS[p] = v;
                if (p == 0) {
                    ans[p].push_back({i, -1});
                } else {
                    ans[p].push_back({i, ans[p - 1].size() - 1});
                }
            }
        }
        /*
        for (auto &vv : ans) {
            for (auto &v : vv)
                cout << '(' << v.first << ',' << v.second << ')' << ' ';
          cout << '\n';
        }
        */
        cout << LIS.size() << '\n';
        int i = LIS.size() - 1, j = ans[i].size() - 1;
        stack<int> res;
        do {
            res.push(ans[i][j].first);
            j = ans[i][j].second; i--;
        } while (i >= 0 && j >= 0);
        while (res.size()) {
            cout << res.top() << ' ';
            res.pop();
        }
        cout << '\n';
    }
}
