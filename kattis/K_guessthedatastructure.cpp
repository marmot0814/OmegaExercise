#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n) {
        vector<bool> ans(3, true);
        stack<int> stk;
        queue<int> que;
        priority_queue<int> pq;
        while (n--) {
            int op, num; cin >> op >> num;
            if (op == 1) {
                stk.push(num);
                que.push(num);
                pq.push(num);
            } else {
                int res;
                if (stk.size()) { 
                    res = stk.top(); stk.pop();
                    if (res != num)
                        ans[0] = false;
                } else ans[0] = false;
                if (que.size()) {
                    res = que.front(); que.pop();
                    if (res != num)
                        ans[1] = false;
                } else ans[1] = false;
                if (pq.size()) {
                    res = pq.top(); pq.pop();
                    if (res != num)
                        ans[2] = false;
                } else ans[2] = false;
            }
        }
        int cnt = 0, idx = -1;
        for (int i = 0 ; i < 3 ; i++) {
            cnt += ans[i];
            if (ans[i])
                idx = i;
        }
        if (cnt == 0) {
            cout << "impossible\n";
        } else if (cnt > 1) {
            cout << "not sure\n";
        } else {
            if (idx == 0)
                cout << "stack\n";
            else if (idx == 1)
                cout << "queue\n";
            else
                cout << "priority queue\n";
        }
    }
}

