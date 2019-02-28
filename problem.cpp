#include <bits/stdc++.h>
using namespace std;
struct Q {
    string name;
    string clas;
};
int main() {
    vector<Q> data;
    string name, clas; while (getline(cin, name)) {
        getline(cin, clas);
        data.push_back({name, clas});
    }
    stable_sort(data.begin(), data.end(), [](Q a, Q b) { return a.clas < b.clas; });
    for (auto &q : data) {
        if (q.name[0] == '0' || q.name[0] == '1')
            continue;
        if (q.clas.substr(0, 1) != "n") continue;
        cout << "- [ ] [kattis " << q.name << "](https://open.kattis.com/problems/" << q.name << ")\n";
        // cout << setw(30) << left << q.name << setw(30) << left << q.clas << '\n';
    }
}
