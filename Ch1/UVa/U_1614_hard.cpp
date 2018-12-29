#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n) {
        vector<pii> data(n);
        LL sum = 0;
        for (int i = 0 ; i < n ; i++) {
            cin >> data[i].first;
            data[i].second = i;
            sum += data[i].first;
        }
        if (sum & 1) {
            cout << "No\n";
            continue;
        }
        sort(data.begin(), data.end());
        reverse(data.begin(), data.end());
        sum /= 2;
        vector<int> res(n, -1);
        for (int i = 0 ; sum != 0 ; i++) {
            if (sum < data[i].first)
                continue;
            sum -= data[i].first;
            res[data[i].second] = 1;
        }
        if (sum == 0) {
            cout << "Yes\n";
            for (int i = 0 ; i < n ; i++)
                cout << res[i] << " \n"[i == n - 1];
        } else
            cout << "No\n";
    }
}
