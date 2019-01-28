#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n; string s; getline(cin, s); 
    vector<vector<int> > pile(n);
    for (int i = 0 ; i < n ; i++)
        pile[i].push_back(i);
    vector<int> pos(n);
    for (int i = 0 ; i < n ; i++)
        pos[i] = i;
    while (getline(cin, s)) {
        if (s[0] == 'q') break;
        stringstream ss; ss << s;
        string x, y; int a, b;
        ss >> x >> a >> y >> b;
        if (pos[a] == pos[b]) continue;
        if (x[0] == 'm') {
            while (pile[pos[a]].back() != a) {
                int p = pile[pos[a]].back();
                pile[p].push_back(p);
                pile[pos[a]].pop_back();
                pos[p] = p;
            }
            if (y[1] == 'n') {
                while (pile[pos[b]].back() != b) {
                    int p = pile[pos[b]].back();
                    pile[p].push_back(p);
                    pile[pos[b]].pop_back();
                    pos[p] = p;
                }
            }
            pile[pos[b]].push_back(a);
            pile[pos[a]].pop_back();
            pos[a] = pos[b];
        } else {
            if (y[1] == 'n') {
                while (pile[pos[b]].back() != b) {
                    int p = pile[pos[b]].back();
                    pile[p].push_back(p);
                    pile[pos[b]].pop_back();
                    pos[p] = p;
                }
            }
            stack<int> stk;
            while (pile[pos[a]].back() != a) {
                stk.push(pile[pos[a]].back());
                pile[pos[a]].pop_back();
            }
            stk.push(a);
            pile[pos[a]].pop_back();
            while (stk.size()) {
                pile[pos[b]].push_back(stk.top());
                pos[stk.top()] = pos[b];
                stk.pop();
            }
        }
    }
    for (int i = 0 ; i < n ; i++) {
        cout << i << ":";
        for (auto &v : pile[i])
            cout << ' ' << v;
        cout << '\n';
    }
}
