#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    map<int, int> x, y;
    for (int i = 0 ; i < 3 ; i++) {
        int a, b; cin >> a >> b;
        x[a]++, y[b]++;
    }
    for (auto &p : x)
        if (p.second == 1)
            cout << p.first << ' ';
    for (auto &p : y)
        if (p.second == 1)
            cout << p.first << '\n';
}
