#include <bits/stdc++.h>
using namespace std;
const string base = "adgjmptw";
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, kase = 0; cin >> t; string input; getline(cin, input); while (t--) {
        cout << "Case #" << ++kase << ": ";
        getline(cin, input);
        int pre = -1;
        for (auto &c : input) {
            if (c == ' ') {
                if (pre == 0)
                    cout << ' ';
                cout << 0;
                pre = 0;
            } else {
                int tar = --upper_bound(base.begin(), base.end(), c) - base.begin();
                if (tar + 2 == pre)
                    cout << ' ';
                for (int i = 0 ; i <= c - base[tar] ; i++)
                    cout << tar + 2;
                pre = tar + 2;
            }
        }
        cout << '\n';
    }
}
