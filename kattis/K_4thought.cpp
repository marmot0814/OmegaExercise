#include <bits/stdc++.h>
using namespace std;
const string op = "+-*/";
long long solve(vector<char> ops) {
    vector<long long> data;
    vector<char> tmp;
    long long sum = 4;
    for (int i = 0 ; i < 3 ; i++) {
        if (ops[i] == '+' || ops[i] == '-') {
            data.push_back(sum);
            tmp.push_back(ops[i]);
            sum = 4;
            continue;
        } else {
            if (ops[i] == '*')
                sum *= 4;
            if (ops[i] == '/')
                sum /= 4;
        }
    }
    data.push_back(sum);
    long long ret = data[0];
    for (int i = 0 ; i < (int)tmp.size() ; i++) {
        if (tmp[i] == '+')
            ret += data[i + 1];
        if (tmp[i] == '-')
            ret -= data[i + 1];
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        long long v; cin >> v;
        bool ok = false;
        for (int i = 0 ; i < 4 ; i++) {
            for (int j = 0 ; j < 4 ; j++) {
                for (int k = 0 ; k < 4 ; k++) {
                    if (v != solve({op[i], op[j], op[k]}))
                        continue;
                    cout << 4 << ' ' << op[i] << " 4 " << op[j] << " 4 " << op[k] << " 4 = " << v << '\n';
                    ok = true;
                    if (ok) break;
                }
                if (ok) break;
            }
            if (ok) break;
        }
        if (!ok) cout << "no solution\n";
    }
}
