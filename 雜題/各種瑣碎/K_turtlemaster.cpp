#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<vector<char> > G(8, vector<char>(8));
    for (auto &vv : G) for (auto &v : vv) cin >> v;
    string op; cin >> op;
    int dir = 0, x = 7, y = 0;
    bool legal = true;
    for (auto &c : op) {
        switch(c) {
            case 'F':
                x += dx[dir], y += dy[dir];
                if (x < 0 || x >= 8 || y < 0 || y >= 8 || G[x][y] == 'C' || G[x][y] == 'I')
                    legal = false;
                break;
            case 'L':
                dir--; dir = (dir + 4) % 4;
                break;
            case 'R':
                dir++; dir = (dir + 4) % 4;
                break;
            case 'X':
                int nx = x + dx[dir], ny = y + dy[dir];
                if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8 || G[nx][ny] != 'I')
                    legal = false;
                else
                    G[nx][ny] = '.';
                break;
        }
        if (!legal) break;
    }
    if (legal && G[x][y] == 'D') {
        cout << "Diamond!\n";
    } else {
        cout << "Bug!\n";
    }
}
