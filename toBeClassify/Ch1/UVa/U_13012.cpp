#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n) {
        int ans = 0;
        for (int i = 0 ; i < 5 ; i++) {
            int num; cin >> num;
            if (n == num)
                ans++;
        }
        cout << ans << '\n';
    }
}
