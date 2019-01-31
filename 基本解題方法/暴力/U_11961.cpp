#include <bits/stdc++.h>
using namespace std;
const char chioce[] = {'A', 'C', 'G', 'T'};
vector<string> ans;
string base;
void solve(int curStep, int k) {
    if (curStep == (int)base.size()) {
        ans.push_back(base);
        return ;
    }
    char ori = base[curStep];
    for (int i = 0 ; i < 4 ; i++) {
        if (ori != chioce[i] && k) {
            base[curStep] = chioce[i];
            solve(curStep + 1, k - 1);
            base[curStep] = ori;
        }
    }
    solve(curStep + 1, k);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n, k; cin >> n >> k >> base;
        ans.clear(); solve(0, k);
        sort(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for (auto &s : ans)
            cout << s << '\n';
    }
}
