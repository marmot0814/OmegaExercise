#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n, m; cin >> n >> m;
        vector<long long> cs, e; long long sum_cs = 0, sum_e = 0;
        for (int i = 0 ; i < n ; i++) {
            long long v; cin >> v;
            cs.push_back(v);
            sum_cs += v;
        }
        for (int i = 0 ; i < m ; i++) {
            long long v; cin >> v;
            e.push_back(v);
            sum_e += v;
        }
        long long ans = 0;
        for (int i = 0 ; i < n ; i++) {
            if (double(sum_cs - cs[i]) / (n - 1) > double(sum_cs) / n && double(sum_e + cs[i]) / (m + 1) > double(sum_e) / m)
                ans++;
        }
        cout << ans << '\n';
    }
}
