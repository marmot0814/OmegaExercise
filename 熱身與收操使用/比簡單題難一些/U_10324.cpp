#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int kase = 0;
    string s; while (cin >> s) {
        cout << "Case " << ++kase << ":\n";
        vector<int> pre; pre.push_back(0);
        for (auto &c : s)
            pre.push_back(pre.back() + c - '0');
        int q; cin >> q; while (q--) {
            int l, r; cin >> l >> r; r++;
            if (pre[r] - pre[l] != r - l && pre[r] - pre[l] != 0)
                cout << "No\n";
            else
                cout << "Yes\n";
        }
    }
    
}
