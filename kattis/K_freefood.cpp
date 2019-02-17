#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<bool> cnt(370, false);
    int t; cin >> t; while (t--) {
        int x, y; cin >> x >> y;
        for (int i = x ; i <= y ; i++)
            cnt[i] = true;
    }
    int sum = 0;
    for (int i = 0 ; i < 370 ; i++)
        sum += cnt[i];
    cout << sum << '\n';
}

