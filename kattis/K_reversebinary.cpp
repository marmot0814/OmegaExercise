#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    string str;
    while (n) {
        str += char(n % 2 + '0');
        n /= 2;
    }
    int ans = 0;
    for (auto &c : str)
        ans *= 2, ans += c - '0';
    cout << ans << '\n';
}
