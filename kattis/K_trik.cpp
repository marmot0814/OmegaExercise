#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<int> G{1, 0, 0};
    string s; cin >> s;
    for (auto &c : s) {
        if (c == 'A')
            swap(G[0], G[1]);
        if (c == 'B')
            swap(G[1], G[2]);
        if (c == 'C')
            swap(G[0], G[2]);
    }
    for (int i = 0 ; i < 3 ; i++)
        if (G[i] == 1)
            cout << i + 1 << '\n';
}
