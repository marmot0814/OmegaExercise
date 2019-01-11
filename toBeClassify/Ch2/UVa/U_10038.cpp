#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n) {
        vector<int> data(n);
        for (auto &v : data)
            cin >> v;
        if (n == 1) {
            cout << "Jolly\n";
        } else {
            vector<bool> used(n, false);
            bool legal = true;
            for (int i = 1 ; i < n ; i++) {
                int x = abs(data[i] - data[i - 1]);
                if (x >= n) {
                    legal = false;
                    break;
                }
                if (used[x]) {
                    legal = false;
                    break;
                } else {
                    used[x] = true;
                }
            }
            if (legal)
                cout << "Jolly\n";
            else 
                cout << "Not jolly\n";
        }
    }
}
