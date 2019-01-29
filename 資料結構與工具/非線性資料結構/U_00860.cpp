#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    map<string, int> cnt; int word = 0;
    string s; while (getline(cin, s)) {
        if (s == "****END_OF_INPUT****") break;
        if (s == "****END_OF_TEXT****") {
            double Et = 0, Emax = 0, Erel;
            for (auto &p : cnt)
                Et += p.second * (log10(word) - log10(p.second));
            Et /= word;
            Emax = log10(word);
            Erel = Et / Emax;
            cout << word << ' ';
            cout << fixed << setprecision(1) << Et << ' ';
            cout << fixed << setprecision(0) << Erel * 100 << '\n';
            cnt.clear();
            word = 0;
            continue;
        }
        for (auto &c : s) {
            switch(c) {
                case ',':case '.':case ':':
                case ';':case '!':case '?':
                case '\"':case '(':case ')':
                    c = ' ';
            }
            c = tolower(c);
        }
        stringstream ss; ss << s;
        string tmp; while (ss >> tmp)
            word++, cnt[tmp]++;
    }
}
