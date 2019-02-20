#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    vector<char> ans;
    for (auto &c : s) {
        if (c == '<' && ans.size())
            ans.pop_back();
        else
            ans.push_back(c);
    }
    for (auto &c : ans)
        cout << c;
    cout << '\n';
}
