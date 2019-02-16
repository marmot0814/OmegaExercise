#include <bits/stdc++.h>
using namespace std;
int trans(char c, bool dou) {
    int tar = (c - '0') * (dou + 1);
    int ret = 0;
    while (tar) {
        ret += tar % 10;
        tar /= 10;
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        string input; cin >> input;
        reverse(input.begin(), input.end());
        bool dou = false;
        long long sum = 0;
        while (input.size()) {
            sum += trans(input.front(), dou);
            dou ^= 1;
            input = input.substr(1, input.size() - 1);
        }
        if (sum % 10)
            cout << "FAIL\n";
        else
            cout << "PASS\n";
    }
}
