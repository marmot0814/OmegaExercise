#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2}; 
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1}; 
int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0);
    LL s = 0;
    int S[5][5] = {
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 1},
        {0, 0, 2, 1, 1},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}
    };
    for (int i = 0 ; i < 5 ; i++)
        for (int j = 0 ; j < 5 ; j++) 
            s *= 3, s += S[i][j];
    map<LL, int> cnt; cnt[s] = 0;
    queue<LL> q; q.push(s);
    while (q.size()) {
        LL p = q.front(); q.pop();
        if (cnt[p] == 10)
            continue;
        LL B[5][5];
        int x = 0, y = 0; LL tar = p;
        for (int i = 4 ; ~i ; i--) {
            for (int j = 4 ; ~j ; j--) {
                B[i][j] = tar % 3;
                tar /= 3;
                if (B[i][j] == 2)
                    x = i, y = j;
            }
        }
        for (int d = 0 ; d < 8 ; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx > 4 || nx < 0 || ny > 4 || ny < 0)
                continue;
            swap(B[x][y], B[nx][ny]);
            LL np = 0;
            for (int i = 0 ; i < 5 ; i++)
                for (int j = 0 ; j < 5 ; j++)
                    np *= 3, np += B[i][j];
            if (!cnt.count(np)) {
                cnt[np] = cnt[p] + 1;
                q.push(np);
            }
            swap(B[x][y], B[nx][ny]);
        }
    }
    int t; cin >> t; string str; getline(cin, str); while (t--) {
        LL e = 0;
        for (int i = 0 ; i < 5 ; i++) {
            getline(cin, str);
            for (int j = 0 ; j < 5 ; j++) {
                e *= 3;
                if (str[j] == '1')
                    e++;
                else if (str[j] == ' ')
                    e += 2;
            }
        }
        if (cnt.count(e)) {
            cout << "Solvable in " << cnt[e] << " move(s).\n";
        } else {
            cout << "Unsolvable in less than 11 move(s).\n";
        }
    }
}
