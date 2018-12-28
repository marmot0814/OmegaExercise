#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    map<string, int> cnt; int ac = 0, pe = 0;
    int n; while (cin >> n) {
        if (n < 0) break;
        string q; cin >> q;
        string st; cin >> st;
        if (cnt.count(q) && cnt[q] == -1)
            continue;
        if (st[0] == 'r') {
            pe += n + cnt[q] * 20;
            ac++; cnt[q] = -1;
        } else {
            cnt[q]++;
        }
    }
    cout << ac << ' ' << pe << '\n';
}
