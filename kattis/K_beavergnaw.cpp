#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int D, V; while (cin >> D >> V && D && V) {
        cout << fixed << setprecision(10) << pow(4 * (D * D * D * PI / 4.0 - V * 3 / 2.0) / PI, 1 / 3.0) << '\n';
    }
}
