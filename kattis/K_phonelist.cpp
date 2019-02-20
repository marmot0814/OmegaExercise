#include <bits/stdc++.h>
using namespace std;
const int SIGMA = 10;
struct Node {
    Node *ch[SIGMA];
    bool end;
    Node () {
        memset(ch, 0, sizeof(ch));
        end = false;
    }
};
void remove(Node *u) {
    if (!u) return ;
    for (int i = 0 ; i < SIGMA ; i++)
        remove(u->ch[i]);
    delete u;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        Node *rt = new Node();
        int n; cin >> n;
        bool ok = true;
        vector<string> data(n);
        for (auto &s : data)
            cin >> s;
        sort(data.begin(), data.end());
        for (int i = 0 ; i < n ; i++) {
            string s = data[i];
            Node *cur = rt;
            for (auto &c : s) {
                if (!cur->ch[c - '0'])
                    cur->ch[c - '0'] = new Node();
                cur = cur->ch[c - '0'];
                if (cur->end)
                    ok = false;
            }
            cur->end = true;
        }
        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";
        remove(rt);
    }
}
