#include <bits/stdc++.h>
using namespace std;
int trans(char c) {
    if (c == 'A') return 0;
    if (c == 'K') return 1;
    if (c == 'Q') return 2;
    if (c == 'J') return 3;
    if (c == 'T') return 4;
    if (c == '9') return 5;
    if (c == '8') return 6;
    if (c == '7') return 7;
    return 8;
}
int dom[] = {11, 4, 3, 20, 10, 14, 0, 0};
int nodom[] = {11, 4, 3, 2, 10, 0, 0, 0};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; char domc; cin >> n >> domc;
    int ans = 0;
    char c, s; while (cin >> c >> s) {
        if (s == domc)
            ans += dom[trans(c)];
        else
            ans += nodom[trans(c)];
    }
    cout << ans << '\n';

}
