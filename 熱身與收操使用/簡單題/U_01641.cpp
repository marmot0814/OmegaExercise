#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m; while (cin >> n >> m) {
        int ans = 0;
        for (int i = 0 ; i < n ; i++) {
            bool ok = false;
            for (int j = 0 ; j < m ; j++) {
                char c; cin >> c;
                if (c != '.') ok ^= 1, ans++;
                else if (ok) ans += (c == '.' ? 2 : 1);
            }
        }
        cout << ans / 2 << '\n';
    }
}
