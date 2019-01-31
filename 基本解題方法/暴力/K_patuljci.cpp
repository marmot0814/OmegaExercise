#include <bits/stdc++.h>
using namespace std;
int sum;
vector<int> ans, _data;
bool solve(int curStep) {
    if ((int)ans.size() == 7 && sum == 100) {
        for (int i = 0 ; i < 7 ; i++)
            cout << ans[i] << '\n';
        return true;
    }
    if (curStep == (int)_data.size()) return false;
    sum += _data[curStep];
    ans.push_back(_data[curStep]);
    if (solve(curStep + 1)) return true;
    sum -= _data[curStep];
    ans.pop_back();
    if (solve(curStep + 1)) return true;
    return false;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    sum = 0; ans.clear(); _data.clear();
    for (int i = 0 ; i < 9 ; i++) {
        int v; cin >> v;
        _data.push_back(v);
    }
    solve(0);
}
