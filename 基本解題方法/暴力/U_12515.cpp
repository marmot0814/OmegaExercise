#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    vector<string> data(n);
    for (auto &s : data) cin >> s;
    while (q--) {
        string tar; cin >> tar;
        int ans = -1, minV = INF;
        for (int i = 0 ; i < (int)data.size() ; i++) {
            if (data[i].size() < tar.size())
                continue;
            string legal_str = "";
            for (auto &c : tar) legal_str += "1";
            bitset<105> base(data[i]), target(tar), legal(legal_str);

            int shift_times = (int)data[i].size() - (int)tar.size() + 1;
            for (int j = 0 ; j < shift_times ; j++, target <<= 1, legal <<= 1) {
                int res = ((base & legal) ^ target).count();
                if (res < minV) {
                    minV = res;
                    ans = i;
                }
            }
        }
        cout << ans + 1 << '\n';
    }
}
