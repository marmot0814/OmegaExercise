#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        LL n; cin >> n;
        vector<pair<LL, LL> > ans;
        for (LL i = 1 ; ; i++) {
            stringstream ss; ss << i;
            string s; ss >> s;
            vector<bool> cnt(10, false);
            bool legal = true;
            for (auto &c : s) {
                if (cnt[c - '0'])
                    legal = false;
                else
                    cnt[c - '0'] = true;
            }
            if (!legal) continue;
            if (i * n > 9876543210) break;
            ss.clear(); ss << (i * n);
            cnt.clear(); cnt.resize(10, false);
            legal = true;
            ss >> s;
            for (auto &c : s)
                if (cnt[c - '0'])
                    legal = false;
                else
                    cnt[c - '0'] = true;
            if (!legal) continue;
            ans.push_back({i * n, i});
        }
        for (auto &p : ans)
            cout << p.first << " / " << p.second << " = " << n << '\n';
        if (t) cout << '\n';
    }
}
