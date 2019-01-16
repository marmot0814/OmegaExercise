#include <bits/stdc++.h>
using namespace std;
struct book {
    string author, title;
    bool borrowed, returned;
    book() {
        borrowed = false;
        returned = true;
    }
    bool operator < (const book &rhs) const {
        return author == rhs.author ? title < rhs.title : author < rhs.author;
    }
};
int main() {
    vector<book> data;
    string input; while (getline(cin, input)) {
        if (input[0] == 'E') break;
        int idx = 0, cnt = 0;
        for (auto &c : input) {
            if (c == '\"')
                cnt++;
            if (cnt == 2)
                break;
            idx++;
        }
        book b;
        b.title = input.substr(0, idx + 1);
        b.author  = input.substr(idx + 5, input.size() - idx + 5);
        data.push_back(b);
    }
    sort(data.begin(), data.end());
    vector<book> return_list;
    while (getline(cin, input)) {
        if (input[0] == 'E') break;
        if (input[0] == 'S') {
            sort(return_list.begin(), return_list.end());
            for (auto &ret_b : return_list ) {
                int idx = 0;
                for (auto &b : data) {
                    if (b.title == ret_b.title)
                        break;
                    idx++;
                }
                bool found = false;
                for (int i = idx - 1 ; ~i ; i--) {
                    if (data[i].returned) {
                        found = true;
                        cout << "Put " << data[idx].title << " after " << data[i].title << '\n';
                        data[idx].borrowed = false;
                        data[idx].returned = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Put " << data[idx].title << " first\n";
                    data[idx].borrowed = false;
                    data[idx].returned = true;
                }
            }
            cout << "END\n";
            return_list.clear();
        } else if (input[0] == 'B') {
            string title = input.substr(7, input.size() - 7);
            for (auto &b : data) {
                if (b.title == title) {
                    b.borrowed = true;
                    b.returned = false;
                    break;
                }
            }
        } else {
            string title = input.substr(7, input.size() - 7);
            for (auto &b : data) {
                if (title != b.title)
                    continue;
                return_list.push_back(b);
                break;
            }
        }
    }
}
