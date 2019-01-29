#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; while (getline(cin, s)) {
        int ones = 0, zeros = 0;
        for (auto &c : s) {
            ones += __builtin_popcount(c);
            zeros += 7 - __builtin_popcount(c);
        }
        if (ones % 2 == 0 && zeros % 2 == 0)
            cout << "free\n";
        else
            cout << "trapped\n";
    }
}
