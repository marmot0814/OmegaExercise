#include <bits/stdc++.h>
using namespace std;
int sz[] = {19, 17, 13, 11, 7, 5, 3, 2};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int sum = 0; vector<int> data;
    for (int i = 0 ; i < 8 ; i++) {
        int v; cin >> v;
        data.push_back(v);
    }
    reverse(data.begin(), data.end());
    for (int i = 0 ; i < 8 ; i++) {
        sum *= sz[i]; sum += data[i];
    }
    cout << 9699689 - sum << '\n';
}
