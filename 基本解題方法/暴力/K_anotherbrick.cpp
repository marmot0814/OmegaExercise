#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int h, w, n; cin >> h >> w >> n;
    int sum = 0;
    bool legal = true;
    for (int i = 0 ; i < n ; i++) {
        int v; cin >> v;
        sum += v;
        if (sum > w && h > 0) {
            legal = false;
        } else if (sum == w) {
            sum = 0;
            h--;
        }
    }
    if (legal) cout << "YES\n";
    else cout << "NO\n";
}
