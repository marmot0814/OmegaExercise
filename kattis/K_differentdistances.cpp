#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    double x1, y1, x2, y2, p;
    while (cin >> x1 && x1) {
        cin >> y1 >> x2 >> y2 >> p;
        cout << fixed << setprecision(10) << pow(pow(abs(x1 - x2), p) + pow(abs(y1 - y2), p), 1 / p) << '\n';
    }
}
