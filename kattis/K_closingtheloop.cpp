#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, kase = 0; cin >> t; while (t--) {
        cout << "Case #" << ++kase << ": ";
        int n; cin >> n;
        vector<int> data[2];
        for (int i = 0 ; i < n ; i++) {
            string s; cin >> s;
            char c = s.back();
            s = s.substr(0, s.size() - 1);
            stringstream ss; ss << s;
            int len; ss >> len;
            if (c == 'R')
                data[0].push_back(len - 1);
            if (c == 'B')
                data[1].push_back(len - 1);
        }
        sort(data[0].begin(), data[0].end(), greater<int>());
        sort(data[1].begin(), data[1].end(), greater<int>());
        int minV = min(data[0].size(), data[1].size());
        int ans = 0;
        for (int i = 0 ; i < minV ; i++)
            ans += data[0][i] + data[1][i];
        cout << ans << '\n';
    }
}
