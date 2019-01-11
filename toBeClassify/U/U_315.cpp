#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 5;
const int MAXM = 1e5 + 5;
struct Graph {
    struct Node; struct Edge;
    struct Node : vector<Edge*> {
        int low, dfn;
        Node *p;
        bool is_cut;
        Node() {
            low = dfn = -1;
            is_cut = false;
        }
    }_memN[MAXN], *node[MAXN];
    struct Edge {
        Node *u, *v;
        Edge(Node *u = NULL, Node *v = NULL) : u(u), v(v) {}
    }_memE[MAXN], *ptrE;
    int n, stamp;
    Graph(int n) : n(n) {
        for (int i = 0 ; i < n ; i++)
            node[i] = _memN + i;
        ptrE = _memE;
        stamp = 0;
    }
    void addEdge(int u, int v) {
        node[u]->push_back(new (ptrE++) Edge(node[u], node[v]));
        node[v]->push_back(new (ptrE++) Edge(node[v], node[u]));
    }
    void Tarjan(Node *u, Node *p) {
        u->dfn = u->low = stamp++;
        u->p = p;
        for (auto &e : *u) {
            if (e->v == p) continue;
            if (~e->v->dfn) {
                u->low = min(u->low, e->v->dfn);
            } else {
                Tarjan(e->v, u);
                u->low = min(u->low, e->v->low);
            }
        }
    }
    int solve() {
        Tarjan(node[0], NULL);
        int root_son = 0;
        for (int i = 1 ; i < n ; i++) {
            Node *u = node[i];
            if (u->p == node[0])
                root_son++;
            else {
                if (u->low >= u->p->dfn)
                    u->p->is_cut = true;
            }
        }
        if (root_son > 1)
            node[0]->is_cut = true;
        int ans = 0;
        for (int i = 0 ; i < n ; i++)
            ans += node[i]->is_cut;
        return ans;
    }
};
int main() {
    int n; while (cin >> n && n) {
        Graph *sol = new Graph(n);
        string s; getline(cin, s); while (getline(cin, s)) {
            stringstream ss; ss << s;
            vector<int> data;
            int tmp; while (ss >> tmp)
                data.push_back(tmp - 1);
            if (!~data[0]) break;
            for (int i = 1 ; i < (int)data.size() ; i++)
                sol->addEdge(data[0], data[i]);
        }
        cout << sol->solve() << '\n';
    }
}
