#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        vector<vector<int> > cnt(2, vector<int>(MAXN, 0));
        for (int i = 0 ; i < 2 ; i++) {
            for (int j = 0 ; j < n ; j++) {
                int v; cin >> v; cnt[i][v]++;
            }
        }
        int minV = 0, maxV = 0;
        for (int i = 0 ; i < MAXN ; i++)
            minV += i * max(cnt[0][i], cnt[1][i]);
        for (int i = 0 ; i < MAXN ; i++)
            for (int j = 0 ; j < MAXN ; j++)
                maxV += min(i, j) * cnt[0][i] * cnt[1][j];
        cout << "Matty needs at least " << minV << " blocks, and can add at most "<< maxV - minV << " extra blocks.\n";
    }
}
