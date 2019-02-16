#include <bits/stdc++.h>
using namespace std;
const string res[] = {"even", "odd"};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        cout << n << " is " << res[abs(n) % 2] << '\n';
    }
}
