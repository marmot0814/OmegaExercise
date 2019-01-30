#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    LL n; while (cin >> n) {
        vector<pair<LL, LL> > ans;
        for (LL i = n + 1 ; i <= 2 * n; i++) {
            if ((n * i) % (i - n) == 0)
                ans.push_back({(n * i) / (i - n), i});
        }
        cout << ans.size() << '\n';
        for (auto &p : ans) {
            cout << "1/" << n << " = 1/" << p.first << " + 1/" << p.second << '\n';;
        }
    }
}
