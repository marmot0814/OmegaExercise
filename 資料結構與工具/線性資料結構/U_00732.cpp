#include <bits/stdc++.h>
using namespace std;
string a, b;
vector<int> stk;
vector<char> ans;
void solve(int a_idx, int b_idx) {
    if (a_idx == (int)a.size() && b_idx == (int)b.size()) {
        for (int i = 0 ; i < (int)ans.size() ; i++)
            cout << ans[i] << " \n"[i == (int)ans.size() - 1];
        return ;
    }
    if (a_idx < (int)a.size()) {
        stk.push_back(a[a_idx]);
        ans.push_back('i');
        solve(a_idx + 1, b_idx);
        stk.pop_back();
        ans.pop_back();
    }
    if (a_idx > b_idx) {
        if (stk.back() == b[b_idx]) {
            ans.push_back('o');
            stk.pop_back();
            solve(a_idx, b_idx + 1);
            stk.push_back(b[b_idx]);
            ans.pop_back();
        }
    }
}
int main() {
    while (getline(cin, a)) {
        getline(cin, b);
        cout << "[\n";
        solve(0, 0);
        cout << "]\n";
    }
}
