#include <bits/stdc++.h>
using namespace std;
int trans(char c) {
    if (c == 'A') return 1;
    if (c == 'T') return 10;
    if (c == 'J') return 11;
    if (c == 'Q') return 12;
    if (c == 'K') return 13;
    return c - '0';
}
int value(int x) {
    if (x == 1) return 4;
    if (x == 11) return 1;
    if (x == 12) return 2;
    if (x == 13) return 3;
    return 0;
}
int main() {
    string card;
    while (cin >> card) {
        if (card[0] == '#') break;
        vector<int> data; data.push_back(trans(card[1]));
        for (int i = 0 ; i < 51 ; i++) {
            cin >> card;
            data.push_back(trans(card[1]));
        }
        queue<int> hand[2], desk;
        for (int i = 51 ; ~i ; i--)
            hand[i % 2].push(data[i]);
        bool round = 0, end = false;
        while (!end) {
            if (!hand[round].size()) break;
            int p = hand[round].front(); hand[round].pop();
            desk.push(p);
            if (value(p) && !end) {
                for (int i = 0 ; i < value(p) && !end ; i++) {
                    if (hand[round ^ 1].size()) {
                        int q = hand[round ^ 1].front(); hand[round ^ 1].pop();
                        desk.push(q);
                        if (value(q)) {
                            p = q;
                            i = -1;
                            round ^= 1;
                            continue;
                        }
                    } else end = true;
                }
                if (!end) {
                    while (desk.size()) {
                        hand[round].push(desk.front());
                        desk.pop();
                    }
                } else break;
                round ^= 1;
            }
            round ^= 1;
        }
        if (hand[0].size() == 0) {
            cout << 1 << setw(3) << hand[1].size() << '\n';
        } else {
            cout << 2 << setw(3) << hand[0].size() << '\n';
        }
    }
}
