#include <bits/stdc++.h>
using namespace std;
bool isleap(int x) {
    if (x % 400 == 0)
        return true;
    if (x % 100 == 0)
        return false;
    if (x % 4 == 0)
        return true;
    return false;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    bool first = true;
    string input; while (cin >> input) {
        if (first) first = false; else cout << '\n';
        int _15 = 0, _55 = 0, _400 = 0;
        for (auto &c : input) {
            _15 *= 10; _15 += c - '0'; _15 %= 15;
            _55 *= 10; _55 += c - '0'; _55 %= 55;
            _400 *= 10; _400 += c - '0'; _400 %= 400;
        }
        bool ori = true;
        if (isleap(_400))
            cout << "This is leap year.\n", ori = false;
        if (_15 == 0)
            cout << "This is huluculu festival year.\n", ori = false;
        if (_55 == 0 && isleap(_400))
            cout << "This is bulukulu festival year.\n", ori = false;
        if (ori)
            cout << "This is an ordinary year.\n";
    }
}
