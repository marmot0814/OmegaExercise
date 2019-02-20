#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    int ans = 1;
    for (auto &c : s)
        if (c == 'L')
            ans *= 2;
        else
            ans = 2 * ans + 1;
    cout << (1 << (n + 1)) - ans << '\n';
}
