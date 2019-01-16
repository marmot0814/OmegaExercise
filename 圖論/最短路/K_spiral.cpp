#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int main() {
    int index[100][100];
    memset(index, 0, sizeof(index));
    int stamp = 0, x = 49, y = 49, cnt = 0;
    vector<pair<int, int> > pos; pos.push_back({-1, -1});
    while (stamp < 10000) {
        for (int d = 0 ; stamp < 10000 ; d++, d %= 4) {
            if (d == 0 || d == 2) cnt++;
            for (int i = 0 ; i < cnt && stamp < 10000 ; i++) {
                index[x][y] = ++stamp;
                pos.push_back({x, y});
                x += dx[d]; y += dy[d];
            }
        }
    }
    vector<bool> isPrime(10005, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2 ; i < 10005 ; i++)
        if (isPrime[i])
            for (int j = i + i ; j < 10005 ; j += i)
                isPrime[j] = false;
    int kase = 0; while (cin >> x >> y) {
        cout << "Case " << ++kase << ": ";
        int dis[100][100]; memset(dis, -1, sizeof(dis));
        pair<int, int> s = pos[x];
        pair<int, int> t = pos[y];
        dis[s.F][s.S] = 0;
        queue<pair<int, int> > q; q.push(s);
        while (q.size()) {
            pair<int, int> p = q.front(); q.pop();
            for (int d = 0 ; d < 4 ; d++) {
                pair<int, int> nt = make_pair(p.F + dx[d], p.S + dy[d]);
                if (nt.F < 0 || nt.F >= 100 || nt.S < 0 || nt.S >= 100)
                    continue;
                if (isPrime[index[nt.F][nt.S]])
                    continue;
                if (~dis[nt.F][nt.S])
                    continue;
                dis[nt.F][nt.S] = dis[p.F][p.S] + 1;
                q.push(nt);
            }
        }
        if (dis[t.F][t.S] == -1)
            cout << "impossible\n";
        else
            cout << dis[t.F][t.S] << '\n';
    }
    
    
}
