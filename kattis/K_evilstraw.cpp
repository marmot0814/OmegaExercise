#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        string s; cin >> s;
        map<char, int> cnt;
        for (auto &c : s)
            cnt[c]++;
        int odd_num = 0;
        for (auto &p : cnt)
            odd_num += p.second % 2;
        if (odd_num > 1) {
            cout << "Impossible\n";
            continue;
        }
        int ans = 0;
        while (s.size()) {
            if (cnt[s.back()] == 1) {
                ans += s.size() / 2;
                cnt[s.back()]--;
            } else {
                for (int i = 0 ;; i++) {
                    if (s[i] != s.back())
                        continue;
                    ans += i;
                    string l = s.substr(0, i);
                    string r = s.substr(i + 1, s.size() - 1);
                    s = l + r;
                    cnt[s.back()] -= 2;
                    break;
                }
            }
            s = s.substr(0, s.size() - 1);
        }
        cout << ans << '\n';
    }
}
