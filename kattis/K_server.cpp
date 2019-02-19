#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, t; cin >> n >> t;
    int sum = 0;
    for (int i = 0 ; i < n ; i++) {
        int v; cin >> v;
        sum += v;
        if (sum > t) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << n << '\n';
}
