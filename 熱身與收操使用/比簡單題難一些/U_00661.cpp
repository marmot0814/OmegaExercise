#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int kase = 0; bool first = true;
    int n, m, c; while (cin >> n >> m >> c) {
        if (!n && !m && !c) break;
        cout << "Sequence " << ++kase << '\n';
        vector<int> data(n);
        for (auto &v : data) cin >> v;
        int sum = 0, ans = 0;
        vector<bool> used(n, false);
        while (m--) {
            int num; cin >> num; num--;
            if (used[num]) {
                sum -= data[num];
            } else {
                sum += data[num];
            }
            used[num] = !used[num];
            ans = max(ans, sum);
        }
        if (ans <= c) {
            cout << "Fuse was not blown.\nMaximal power consumption was " << ans << " amperes.\n";
        } else {
            cout << "Fuse was blown.\n";
        }
        cout << '\n';
    }
}
