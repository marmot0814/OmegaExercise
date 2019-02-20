#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        vector<int> data(n);
        int sum = 0;
        for (auto &v : data) {
            cin >> v;
            sum += v;
        }
        int cnt = 0;
        for (auto &v : data)
            cnt += v * n > sum;
        double ans = cnt * 100.0 / n;
        ans = int(ans * 1000 + .5) / 1000.;
        cout << fixed << setprecision(3) << ans << "%\n";
    }
}
