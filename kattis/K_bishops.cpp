#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n) {
        cout << n + max(0, n - 2) << '\n';
    }
}
