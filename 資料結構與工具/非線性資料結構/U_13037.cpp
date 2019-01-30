#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int kase = 0;
    int t; cin >> t; while (t--) {
        cout << "Case #" << ++kase << ":\n";
        int n[3]; cin >> n[0] >> n[1] >> n[2];
        unordered_set<int> cnt[3], total;
        for (int i = 0 ; i < 3 ; i++) {
            for (int j = 0 ; j < n[i] ; j++) {
                int num; cin >> num;
                cnt[i].insert(num);
                total.insert(num);
            }
        }
        int ans[3][2]; memset(ans, 0, sizeof(ans));
        for (int i = 0 ; i < 3 ; i++) {
            for (auto &v : total) {
                if (!cnt[(i + 1) % 3].count(v) && !cnt[(i + 2) % 3].count(v) &&  cnt[i].count(v))
                    ans[i][0]++;
                if ( cnt[(i + 1) % 3].count(v) &&  cnt[(i + 2) % 3].count(v) && !cnt[i].count(v))
                    ans[i][1]++;
            }
            cout << ans[i][0] << ' ' << ans[i][1] << '\n';
        }
    }
}
