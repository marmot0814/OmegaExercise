
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n, m; cin >> n >> m;
        int max_n = 0, max_m = 0;
        for (int i = 0 ; i < n ; i++) {
            int num; cin >> num;
            max_n = max(max_n, num);
        }
        for (int i = 0 ; i < m ; i++) {
            int num; cin >> num;
            max_m = max(max_m, num);
        }
        if (max_n < max_m)
            cout << "MechaGodzilla\n";
        else
            cout << "Godzilla\n";
    }
}
