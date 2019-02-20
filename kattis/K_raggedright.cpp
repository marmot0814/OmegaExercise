#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<int> data; int maxV = 0;
    string input; while (getline(cin, input)) {
        data.push_back(input.size());
        maxV = max(maxV, data.back());
    }
    data.pop_back();
    int ans = 0;
    for (auto &v : data)
        ans += (v - maxV) * (v - maxV);
    cout << ans << '\n';
}
