#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    bool first = true;
    int n; while (cin >> n && n) {
        if (first) first = false; else cout << '\n';
        vector<string> data(n);
        for (auto &s : data) cin >> s;
        stable_sort(data.begin(), data.end(), [](string a, string b) { return a.substr(0, 2) < b.substr(0, 2); });
        for (auto &s : data)
            cout << s << '\n';
    }
}
