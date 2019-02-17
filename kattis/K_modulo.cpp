#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    set<int> app;
    for (int i = 0 ; i < 10 ; i++) {
        int n; cin >> n;
        app.insert(n % 42);
    }
    cout << app.size() << '\n';
}
