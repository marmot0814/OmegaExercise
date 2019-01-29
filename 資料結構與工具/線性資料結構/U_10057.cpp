#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n) {
        vector<int> data(n);
        for (auto &v : data) cin >> v;
        sort(data.begin(), data.end());
        if (n == 1) {
            cout << data[0] << ' ' << 1 << ' ' << 1 << '\n';
        } else if (n % 2) {
            int target = data[n / 2];
            int cnt = 0;
            for (auto &v : data)
                if (v == target)
                    cnt++;
            cout << target << ' ' << cnt << ' ' << 1 << '\n';
        } else {
            int target_1 = data[n / 2 - 1];
            int target_2 = data[n / 2];
            int cnt = 0;
            for (auto &v : data)
                if (v == target_1 || v == target_2)
                    cnt++;
            cout << target_1 << ' ' << cnt << ' ' << target_2 - target_1 + 1 << '\n';
        }
    }
}
