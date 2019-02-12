#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    int rank = 25, star = 0, cnt = 0;
    vector<int> need{0};
    for (int i = 0 ; i < 10 ; i++) need.push_back(5);
    for (int i = 0 ; i < 5  ; i++) need.push_back(4);
    for (int i = 0 ; i < 5  ; i++) need.push_back(3);
    for (int i = 0 ; i < 5  ; i++) need.push_back(2);
    for (auto &c : s) {
        if (rank == 0) continue;
        if (c == 'W') {
            cnt++;
            star += (cnt >= 3 && rank >= 6) + 1;
            if (star > need[rank])
                star -= need[rank], rank--;
        } else {
            cnt = 0;
            if (rank > 20 || (rank == 20 && star == 0)) continue;
            star--;
            if (star < 0)
                rank++, star = need[rank] - 1;
        }
    }
    if (rank)
        cout << rank << '\n';
    else
        cout << "Legend\n";
}
