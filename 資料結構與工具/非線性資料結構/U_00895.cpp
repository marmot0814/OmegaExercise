#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<vector<int> > cnt;
    string s; while (cin >> s) {
        if (s[0] == '#') break;
        vector<int> vv(26, 0);
        for (auto &c : s)
            vv[c - 'a']++;
        cnt.push_back(vv);
    }
    getline(cin, s); while (getline(cin, s)) {
        if (s[0] == '#') break;
        stringstream ss; ss << s;
        vector<int> vv(26, 0);
        char tmp; while (ss >> tmp) vv[tmp - 'a']++;
        int ans = 0;
        for (auto &v : cnt) {
            bool ok = true;
            for (int i = 0 ; i < 26 && ok ; i++)
                if (v[i] > vv[i])
                    ok = false;
            ans += ok;
        }
        cout << ans << '\n';
    }
}
