#include <bits/stdc++.h>
using namespace std;
int main() {
    int ans, n; cin >> ans >> n; ans--;
    int cnt = 0;
    while (n--) {
        int t; char c;
        cin >> t >> c;
        cnt += t;
        if (cnt >= 210)
            break;
        if (c == 'T')
            ans++, ans %= 8;
    }
    cout << ans + 1 << '\n';
}
