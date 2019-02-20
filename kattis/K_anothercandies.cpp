#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        long long sum = 0;
        for (int i = 0 ; i < n ; i++) {
            long long v; cin >> v;
            sum += v;
            sum %= n;
        }
        if (sum)
            cout << "NO\n";
        else
            cout << "YES\n";

    }
}
