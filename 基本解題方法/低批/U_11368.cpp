#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        vector<pii> data(n);
        for (auto &p : data)
            cin >> p.F >> p.S;
        sort(data.begin(), data.end());
        map<int, int> candid, buf;
        buf[data[0].S]++;
        int ans = 1;
        for (int i = 1 ; i < n ; i++) {
            if (data[i].F != data[i - 1].F) {
                for (auto &p : buf)
                    candid[p.F] += p.S;
                buf.clear();
            }
            auto it = candid.lower_bound(data[i].S);
            if (it != candid.begin()) {
                it--;
                if (it->S == 1)
                    candid.erase(it);
                else
                    candid[it->F]--;
            } else ans++;
            buf[data[i].S]++;
        }
        cout << ans << '\n';
    }
}
