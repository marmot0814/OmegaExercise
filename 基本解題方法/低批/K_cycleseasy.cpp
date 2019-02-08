#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, kase = 0; cin >> t; while (t--) {
        cout << "Case #" << ++kase << ": ";
        int n, k; cin >> n >> k;
        vector<pii> con(k);
        for (auto &p : con) cin >> p.F >> p.S;
        vector<int> per;
        for (int i = 2 ; i <= n ; i++)
            per.push_back(i);
        int ans = 0;
        set<vector<int> > app;
        do {
            bool legal = true;
            for (auto &p : con) {
                for (int i = 1 ; i < n - 1 ; i++)
                    if (min(p.F, p.S) == min(per[i - 1], per[i]) && max(p.F, p.S) == max(per[i - 1], per[i]))
                        legal = false;
                if (min(p.F, p.S) == 1 && max(p.F, p.S) == per.front())
                    legal = false;
                if (min(p.F, p.S) == 1 && max(p.F, p.S) == per.back())
                    legal = false;
            }
            if (!legal) continue;
            vector<int> test = per;
            if (app.count(test))
                legal = false;
            reverse(test.begin(), test.end());
            if (app.count(test))
                legal = false;
            ans += legal;
            if (legal) app.insert(test);
        } while (next_permutation(per.begin(), per.end()));
        cout << ans % 9901 << '\n';
    }
}
