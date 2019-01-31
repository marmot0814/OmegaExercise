#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        LL p, q; cin >> p >> q;
        string ans = "";
        LL cnt = min(p / 2, q);
        for (int i = 0 ; i < cnt ; i++)
            ans += "101";
        p -= cnt * 2, q -= cnt;
        if (p && q) ans = "1" + ans, p--;
        while (p) p--, ans += "1";
        LL res = 0;
        for (auto &c : ans)
            res *= 2, res += c - '0';
        cout << res << '\n';
    }
}
