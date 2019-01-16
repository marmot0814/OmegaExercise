#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    int ans = -1;
    for (int i = 0 ; i < n ; i++) {
        int num; cin >> num;
        if (ans > -1) continue;
        if (num > m)
            ans--;
        else
            ans = abs(ans);
    }
    ans = abs(ans) - 1;
    if (ans == n) {
        cout << "It had never snowed this early!\n";
    } else {
        cout << "It hadn't snowed this early in " << ans << " years!\n";
    }
}
