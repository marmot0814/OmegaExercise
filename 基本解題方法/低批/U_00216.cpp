#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
const double INF = 1e10;
double dist(pii a, pii b) {
    return sqrt((a.F - b.F) * (a.F - b.F) + (a.S - b.S) * (a.S - b.S));
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, kase = 0; while (cin >> n && n) {
        vector<pii> pos(n);
        for (auto &p : pos) cin >> p.F >> p.S;
        vector<int> per;
        for (int i = 0 ; i < n ; i++)
            per.push_back(i);
        double minV = INF;
        vector<int> ans;
        do {
            double sum = 0;
            for (int i = 1 ; i < n ; i++) {
                sum += dist(pos[per[i - 1]], pos[per[i]]) + 16;
            }
            if (sum < minV) {
                minV = sum;
                ans = per;
            }
        } while (next_permutation(per.begin(), per.end()));
        cout << fixed << setprecision(2);
        cout << "**********************************************************\n";
        cout << "Network #" << ++kase << '\n';
        for (int i = 1 ; i < n ; i++)
            cout << "Cable requirement to connect (" << pos[ans[i - 1]].F << "," << pos[ans[i - 1]].S << ") to (" << pos[ans[i]].F << "," << pos[ans[i]].S << ") is " << dist(pos[ans[i - 1]], pos[ans[i]]) + 16 << " feet.\n";
        cout << "Number of feet of cable required is " << minV << ".\n";
    }
}
