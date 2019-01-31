#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<int> data(6);
    for (auto &v : data) cin >> v;
    int sum; cin >> sum;
    vector<int> ans[2];
    vector<int> selected{0, 0, 0, 1, 1, 1};
    do {
        int cal = 0;
        for (int i = 0 ; i < 6 ; i++)
            cal += selected[i] * data[i];
        if (cal == sum) {
            ans[0].clear(); ans[1].clear();
            for (int i = 0 ; i < 6 ; i++)
                ans[selected[i]].push_back(data[i]);
            break;
        }
    } while (next_permutation(selected.begin(), selected.end()));
    sort(ans[0].begin(), ans[0].end(), [](int a, int b){ return a > b; });
    sort(ans[1].begin(), ans[1].end(), [](int a, int b){ return a > b; });
    for (int i = 0 ; i < 3 ; i++)
        cout << ans[1][i] << ' ';
    for (int i = 0 ; i < 3 ; i++)
        cout << ans[0][i] << ' ';
}
