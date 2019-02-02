#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
struct Graph{
    struct Node : vector<Node*> {
        int dfn, low, scc;
        bool in_stk;
        Node () { clear(); 
            dfn = low = scc = -1; 
            in_stk = false; 
        }
    }_memN[MAXN], *node[MAXN];
    int V;
    Graph(int _V) : V(_V) {
        for (int i = 0 ; i < V ; i++)
            node[i] = _memN + i;
    }
    void addEdge(int u, int v){
        node[u]->push_back(node[v]);
    }
    int stamp, scc_num; stack<Node*> stk;
    int findSCC(){
        stamp = scc_num = 0;
        for (int i = 0 ; i < V ; i++) {
            auto u = node[i];
            if (!~u->dfn)
                Tarjan(u);
        }
        return scc_num;
    }
    void Tarjan(Node *u) {
        u->dfn = u->low = stamp++;
        stk.push(u); u->in_stk = true;
        for (auto to : *u){
            if (!~to->dfn) {
                Tarjan(to);
                u->low = min(u->low, to->low);
            }else if (to->in_stk)
                u->low = min(u->low, to->dfn);
        }
        if (u->dfn == u->low){
            Node *v;
            do {
                v = stk.top(); stk.pop();
                v->scc = scc_num;
                v->in_stk = false;
            }while (v != u);
            scc_num++;
        }
    }
};
map<char, int> ID;
vector<char> NAME;
int getID(char c) {
    int sz = ID.size();
    if (!ID.count(c))
        ID[c] = sz, NAME.push_back(c);
    return ID[c];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    bool first = true;
    int n; while (cin >> n && n) {
        if (first) first = false; else cout << '\n';
        ID.clear(); NAME.clear();
        vector<pair<int, int> > edges;
        for (int i = 0 ; i < n ; i++) {
            vector<char> candid(5);
            for (auto &v : candid) cin >> v;
            char u; cin >> u;
            for (auto &v : candid) {
                if (v == u) continue;
                edges.push_back({getID(u), getID(v)});
            }
        }
        Graph *sol = new Graph(ID.size());
        for (auto &e : edges)
            sol->addEdge(e.first, e.second);
        vector<string> ans(sol->findSCC(), "");
        for (int i = 0 ; i < (int)NAME.size() ; i++)
            ans[sol->node[i]->scc] += NAME[i];
        for (auto &s : ans) sort(s.begin(), s.end());
        sort(ans.begin(), ans.end());
        for (auto &s : ans)
            for (int i = 0 ; i < (int)s.size() ; i++)
                cout << s[i] << " \n"[i == (int)s.size() - 1];
        delete sol;
    }
}
