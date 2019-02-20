#include <bits/stdc++.h>
using namespace std;
void insert(int v, int i, vector<int> &heap) {
    if (!~heap[i])
        heap[i] = v;
    else {
        if (v > heap[i])
            insert(v, 2 * i + 1, heap);
        else
            insert(v, 2 * i, heap);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    set<string> app;
    while (n--) {
        vector<int> heap((1<<k) + 5, -1);
        for (int i = 0 ; i < k ; i++) {
            int v; cin >> v;
            insert(v, 1, heap);
        }
        string res;
        for (auto &x : heap) {
            if (x == -1)
                res += '0';
            else
                res += '1';
        }
        app.insert(res);
    }
    cout << app.size() << '\n';
}
