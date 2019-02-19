#include <bits/stdc++.h>
using namespace std;
const string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";
int getIdx(char c) {
    if (isalpha(c))
        return c - 'A';
    if (c == '_')
        return 26;
    if (c == '.')
        return 27;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n && n) {
        string s; cin >> s;
        reverse(s.begin(), s.end());
        for (auto &c : s) {
            int idx = getIdx(c);
            idx += n; idx %= 28;
            c = str[idx];
        }
        cout << s << '\n';
    }
}
