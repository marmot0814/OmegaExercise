#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int h, v; cin >> h >> v;
    cout << ceil(h / sin(v * PI / 180)) << '\n';
}
