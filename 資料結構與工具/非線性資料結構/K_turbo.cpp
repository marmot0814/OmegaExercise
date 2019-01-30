#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
template<class TIn>
using indexed_set = tree<
    TIn, null_type, less<TIn>,rb_tree_tag,
    tree_order_statistics_node_update>;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    indexed_set<pair<int, int> > byidx, bynum;
    int n; cin >> n;
    for (int i = 0 ; i < n ; i++) {
        int v; cin >> v;
        byidx.insert({i, v});
        bynum.insert({v, i});
    }
    int cnt = 0;
    while (bynum.size()) {
        pair<int, int> tar;
        if (cnt % 2) {
            tar = *prev(bynum.end());
            cout << bynum.size() - 1 - byidx.order_of_key({tar.second, tar.first}) << '\n';
        } else {
            tar = *bynum.begin();
            cout << byidx.order_of_key({tar.second, tar.first}) << '\n';
        }
        bynum.erase(tar);
        byidx.erase({tar.second, tar.first});
        cnt++;
    }
}
