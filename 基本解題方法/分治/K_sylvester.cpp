#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int solve(LL n, LL x, LL y) {
    if (n == 1) return 1;
    if (x >= n / 2 && y >= n / 2)
        return -solve(n / 2, x % (n / 2), y % (n / 2));
    return solve(n / 2, x % (n / 2), y % (n / 2));
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        LL n, x, y; int w, h;
        cin >> n >> x >> y >> w >> h;
        for (int i = 0 ; i < h ; i++)
            for (int j = 0 ; j < w ; j++)
                cout << solve(n, y + i, x + j) << " \n"[j == w - 1];
        cout << '\n';
    }
}
