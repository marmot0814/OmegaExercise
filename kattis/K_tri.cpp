#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int a, b, c; cin >> a >> b >> c;
    if (a + b == c)
        return cout << a << '+' << b << '=' << c, 0;
    if (a - b == c)
        return cout << a << '-' << b << '=' << c, 0;
    if (a * b == c)
        return cout << a << '*' << b << '=' << c, 0;
    if (a % b == 0 && a / b == c)
        return cout << a << '/' << b << '=' << c, 0;
    if (a == b + c)
        return cout << a << '=' << b << '+' << c, 0;
    if (a == b - c)
        return cout << a << '=' << b << '-' << c, 0;
    if (a == b * c)
        return cout << a << '=' << b << '*' << c, 0;
    if (b % c == 0 && a == b / c)
        return cout << a << '=' << b << '/' << c, 0;
}
