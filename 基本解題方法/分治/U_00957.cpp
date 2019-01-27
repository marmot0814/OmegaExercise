#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int Y, n; while (cin >> Y >> n) {
        int ans = 0, ans_F = -1, ans_S = -1;
        queue<int> q;
        for (int i = 0 ; i < n ; i++) {
            int num; cin >> num;
            while (q.size() && (num - q.front()) >= Y)
                q.pop();
            q.push(num);
            if (ans < (int)q.size()) {
                ans = q.size();
                ans_F = q.front();
                ans_S = num;
            }
        }
        cout << ans << ' ' << ans_F << ' ' << ans_S << '\n';
    }
}
