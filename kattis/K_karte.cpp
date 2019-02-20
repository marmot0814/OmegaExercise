#include <bits/stdc++.h>
using namespace std;
int trans(char c) {
    if (c == 'P')
        return 0;
    if (c == 'K')
        return 1;
    if (c == 'H')
        return 2;
    if (c == 'T')
        return 3;
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string input; cin >> input;
    vector<vector<bool> > app(4, vector<bool>(13, false));
    bool ok = true;
    for (int i = 0 ; i < (int)input.size() ; i += 3) {
        string tar = input.substr(i, 3);
        char T = tar[0];
        int num = 10 * (tar[1] - '0') + tar[2] - '0' - 1;
        if (app[trans(T)][num])
            ok = false;
        app[trans(T)][num] = true;
    }
    if (!ok)
        cout << "GRESKA\n";
    else for (int i = 0 ; i < 4 ; i++) {
        int sum = 0;
        for (int j = 0 ; j < 13 ; j++)
            sum += app[i][j];
        cout << 13 - sum << " \n"[i == 3];
    }
}
