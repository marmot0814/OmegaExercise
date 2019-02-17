#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    map<char, int> cnt;
    for (auto &c : s)
        cnt[c]++;
    int ans = 0, minV = INF;
    for (auto &p : cnt)
        ans += p.second * p.second, minV = min(minV, p.second);
    if ((int)cnt.size() == 3)
        ans += 7 * minV;
    cout << ans << '\n';
}
