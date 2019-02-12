#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int kase = 0;
    int t; cin >> t; while (t--) {
        cout << "Case #" << ++kase << ": ";
        int n; cin >> n;
        map<string, int> data;
        string input; getline(cin, input);
        for (int i = 0 ; i < n ; i++) {
            getline(cin, input);
            data[input] = 0;
        }
        int q; cin >> q; getline(cin, input);
        int cnt = 0, round = 1;
        while (q--) {
            getline(cin, input);
            if (data[input] == round)
                continue;
            data[input] = round;
            cnt++;
            if (cnt == n) {
                round++, cnt = 1;
                data[input] = round;
            }
        }
        cout << round - 1 << '\n';
    }
}
