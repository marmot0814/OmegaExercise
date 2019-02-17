#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    if (n > m) swap(n, m);
    for (int i = n + 1 ; i <= m + 1 ; i++)
        cout << i << '\n';
}

