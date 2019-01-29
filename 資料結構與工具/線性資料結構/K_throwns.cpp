#include <bits/stdc++.h>
using namespace std;
int trans(int cur, int n) {
    while (cur < 0) cur += n;
    return cur % n;
}
int main() {
    int n, q; cin >> n >> q;
    vector<int> ans{0};
    int cur = 0;
    while (q--) {
        string s; cin >> s;
        if (s[0] == 'u') {
            int m; cin >> m;
            for (int i = 0 ; i < m ; i++)
                ans.pop_back();
            cur = ans.back();
        } else {
            stringstream ss; ss << s;
            int tmp; ss >> tmp;
            cur += tmp;
            cur = trans(cur, n);
            ans.push_back(cur);
        }
    }
    cout << ans.back() << '\n';
}
