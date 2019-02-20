#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    map<string, int> str2int;
    map<int, string> int2str;
    string op; while (cin >> op) {
        if (op[0] == 'd') {
            string name; int v;
            cin >> name >> v;
            if (str2int.count(name)) {
                int2str.erase(str2int[name]);
                str2int.erase(name);
            }
            str2int[name] = v;
            int2str[v] = name;
        } else if (op[1] == 'a') {
            int sum = 0;
            bool ok = true;
            string base; cin >> base;
            cout << base;
            if (str2int.count(base))
                sum = str2int[base];
            else
                ok = false;
            string oper;
            while (cin >> oper) {
                cout << ' ' << oper;
                if (oper == "=") {
                    if (!int2str.count(sum))
                        ok = false;
                    if (ok)
                        cout << ' ' << int2str[sum] << '\n';
                    else
                        cout << " unknown\n";
                    break;
                } else {
                    cin >> base;
                    cout << ' ' << base;
                    if (str2int.count(base)) {
                        if (oper == "+")
                            sum += str2int[base];
                        else
                            sum -= str2int[base];
                    } else ok = false;
                }
            }
        } else {
            str2int.clear();
            int2str.clear();
        }
    }
}
