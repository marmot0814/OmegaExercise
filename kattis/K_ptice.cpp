#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    string A, B, C;
    while ((int)A.size() < n)
        A += "ABC";
    while ((int)B.size() < n)
        B += "BABC";
    while ((int)C.size() < n)
        C += "CCAABB";
    vector<int> ans(3, 0);
    for (int i = 0 ; i < (int)s.size() ; i++) {
        if (s[i] == A[i])
            ans[0]++;
        if (s[i] == B[i])
            ans[1]++;
        if (s[i] == C[i])
            ans[2]++;
    }
    int maxV = max({ans[0], ans[1], ans[2]});
    cout << maxV << '\n';
    if (ans[0] == maxV)
        cout << "Adrian\n";
    if (ans[1] == maxV)
        cout << "Bruno\n";
    if (ans[2] == maxV)
        cout << "Goran\n";
}
