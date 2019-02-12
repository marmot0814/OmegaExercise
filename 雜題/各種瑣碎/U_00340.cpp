#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int kase = 0;
    int n; while (cin >> n && n) {
        cout << "Game " << ++kase << ":\n";
        vector<int> ans(n), cnt(10, 0);
        for (auto &v : ans)
            cin >> v, cnt[v]++;
        while (1) {
            vector<int> input(n), input_cnt(10, 0);
            for (auto &v : input)
                cin >> v, input_cnt[v]++;
            if (!input[0])
                break;
            int x = 0, y = 0;
            for (int i = 1 ; i < 10 ; i++)
                y += min(input_cnt[i], cnt[i]);
            for (int i = 0 ; i < n ; i++)
                if (input[i] == ans[i])
                    x++, y--;
            cout << "    (" << x << "," << y << ")\n";
        }
    }
}
