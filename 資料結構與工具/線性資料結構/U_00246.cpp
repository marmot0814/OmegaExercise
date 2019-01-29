#include <bits/stdc++.h>
using namespace std;
void trans(deque<int> &x, queue<int> &q) {
    while (x.size() >= 3) {
        if ((x[0] + x[1] + x[x.size() - 1]) % 10 == 0) {
            q.push(x[0]); q.push(x[1]); q.push(x[x.size() - 1]);
            x.pop_front(); x.pop_front(); x.pop_back();
        } else if ((x[0] + x[x.size() - 2] + x[x.size() - 1]) % 10 == 0) {
            q.push(x[0]); q.push(x[x.size() - 2]); q.push(x[x.size() - 1]);
            x.pop_front(); x.pop_back(); x.pop_back();
        } else if ((x[x.size() - 3] + x[x.size() - 2] + x[x.size() - 1]) % 10 == 0) {
            q.push(x[x.size() - 3]); q.push(x[x.size() - 2]); q.push(x[x.size() - 1]);
            x.pop_back(); x.pop_back(); x.pop_back();
        } else break;
    }
}
struct State {
    int v[64];
    State() { memset(v, 0, sizeof(v)); }
    bool operator < (const State &rhs) const {
        return memcmp(v, rhs.v, sizeof(v)) < 0;
    }
};
int main() {
    while (1) {
        queue<int> cards;
        set<State> app;
        for (int i = 0 ; i < 52 ; i++) {
            int x; cin >> x;
            if (x == 0) return 0;
            cards.push(x);
        }
        deque<int> player[7];
        for (int i = 0 ; i < 2 ; i++)
            for (int j = 0 ; j < 7 ; j++)
                player[j].push_back(cards.front()), cards.pop();
        int ans = 14;
        bool end = false;
        while (!end) {
            for (int i = 0 ; i < 7 ; i++) {
                if (!player[i].size()) continue;
                ans++;
                player[i].push_back(cards.front()), cards.pop();
                trans(player[i], cards);
                if (cards.size() == 52) {
                    cout << "Win : " << ans << '\n';
                    end = true;
                    break;
                }
                if (cards.size() == 0) {
                    cout << "Loss: " << ans << "\n";
                    end = true;
                    break;
                }
                State s; int idx = 0;
                for (int j = 0 ; j < 7 ; j++) {
                    for (auto &v : player[j])
                        s.v[idx++] = v;
                    s.v[idx++] = -1;
                }
                queue<int> q = cards;
                while (q.size())
                    s.v[idx++] = q.front(), q.pop();
                s.v[idx++] = -1;
                if (app.count(s)) {
                    cout << "Draw: " << ans << '\n';
                    end = 1;
                    break;
                } else app.insert(s);
            }
        }
    }
}
