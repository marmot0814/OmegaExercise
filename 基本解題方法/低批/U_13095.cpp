#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n) {
        vector<vector<int> > pre(10);
        for (int i = 0 ; i < 10 ; i++)
            pre[i].push_back(0);
        for (int i = 0 ; i < n ; i++) {
            int num; cin >> num;
            for (int j = 0 ; j < 10 ; j++) {
                if (j == num)
                    pre[j].push_back(pre[j].back() + 1);
                else
                    pre[j].push_back(pre[j].back());
            }
        }
        int q; cin >> q; while (q--) {
            int l, r; cin >> l >> r;
            int ans = 0;
            for (int i = 0 ; i < 10 ; i++)
                if (pre[i][r] - pre[i][l - 1])
                    ans++;
            cout << ans << '\n';
        }
    }
}
