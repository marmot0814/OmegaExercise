#include <bits/stdc++.h>
using namespace std;
struct pss {
    string first;
    string second;
    bool operator < (const pss &rhs) const {
        return first < rhs.first;
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    set<string> ignore;
    vector<pss> data;
    string s; while (getline(cin, s)) {
        if (s[0] == ':') break;
        for (auto &c : s) c = tolower(c);
        ignore.insert(s);
    }
    while (getline(cin, s)) {
        for (auto &c : s) c = tolower(c);
        stringstream ss; ss << s;
        string BASE = "";
        bool first = true;
        string target; while (ss >> target) {
            if (first) first = false; else BASE += " ";
            if (ignore.count(target)) {
                BASE += target;
            } else {
                for (auto &c : target) c = toupper(c);
                data.push_back({target, BASE + target + s.substr(BASE.size() + target.size(), s.size() - BASE.size() - target.size())});
                for (auto &c : target) c = tolower(c);
                BASE += target;
            }
        }
    }
    stable_sort(data.begin(), data.end());
    for (auto &p : data)
        cout << p.second << '\n';

}
