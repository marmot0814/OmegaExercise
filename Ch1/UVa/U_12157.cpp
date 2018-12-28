#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int kase = 0;
    int t; cin >> t; while (t--) {
        cout << "Case " << ++kase << ": ";
        int n; cin >> n;
        int ans_1 = 0, ans_2 = 0;
        for (int i = 0 ; i < n ; i++) {
            int x; cin >> x;
            ans_1 += (x / 30 + 1) * 10;
            ans_2 += (x / 60 + 1) * 15;
        }
        if (ans_1 == ans_2) {
            cout << "Mile Juice " << ans_1 << '\n';
        } else if (ans_1 > ans_2) {
            cout << "Juice " << ans_2 << '\n';
        } else {
            cout << "Mile " << ans_1 << '\n';
        }
    }
}
