#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int x, y, x1, y1, x2, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    int a, b;
    if (x > x2) a = x2;
    else if (x < x1) a = x1;
    else a = x;
    if (y > y2) b = y2;
    else if (y < y1) b = y1;
    else b = y;
    cout << fixed << setprecision(10) << hypot(a - x, b - y) << '\n';
}
