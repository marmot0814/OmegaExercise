#include <bits/stdc++.h>
using namespace std;
map<string, string> mapping;
string target;
vector<string> ans;
string trailing_out(string s, int &cnt) {
    cnt = 0;
    while (s[0] == '0')
        s = s.substr(1, s.size() - 1), cnt++;
    return s;
}
int idx;
void solve(string cur, string ans_str) {
    if (idx >= 100) return ;
    if (cur == target) {
        cout << ans_str << '\n';
        idx++;
        return ;
    }
    for (auto &p : mapping) {
        int cnt = 0;
        if (p.second != trailing_out(target.substr(cur.size(), target.size() - cur.size()), cnt).substr(0, p.second.size()))
            continue;
        solve(cur + target.substr(cur.size(), cnt + p.second.size()), ans_str + p.first);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    bool first = true;
    int n, kase = 0; while (cin >> n && n) {
        mapping.clear(); ans.clear();
        cout << "Case #" << ++kase << '\n';
        idx = 0;
        for (int i = 0 ; i < n ; i++) {
            string a, b; cin >> a >> b;
            mapping[a] = b;
        }
        cin >> target; solve("", "");
        cout << '\n';
    }
}
