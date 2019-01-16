#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200;
const int MAXM = MAXN * MAXN;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
struct Graph { int n;
    struct Node; struct Edge;
    struct Node : vector<Edge*> {
        int d;
    }_memN[MAXN], *node[MAXN], *s, *t;
    struct Edge {
        Node *v; Edge *r; LL c;
        Edge() {}
        Edge(Node *v, Edge *r, LL c) : v(v), r(r), c(c) {}
    }_memE[MAXM], *ptrE;
    inline void addEdge(int u, int v, LL c) {
        Edge *pos = ptrE;
        node[u]->emplace_back(new (ptrE++) Edge(node[v], pos + 1, c));
        node[v]->emplace_back(new (ptrE++) Edge(node[u], pos, 0));
    }
    Graph (int n) : n(n) {
        for (int i = 0 ; i < n ; i++)
            node[i] = _memN + i;
        ptrE = _memE;
    }
    inline LL maxFlow(int _s, int _t) {
        s = node[_s]; t = node[_t];
        LL flow = 0;
        while (bfs())
            flow += dfs(s, INF);
        return flow;
    }
    inline bool bfs() {
        for (int i = 0 ; i < n ; i++)
            node[i]->d = -1;
        s->d = 0;
        queue<Node*> q; q.push(s);
        while (q.size()) {
            auto u = q.front(); q.pop();
            for (auto &e : *u) {
                if (!e->c || ~e->v->d)
                    continue;
                e->v->d = u->d + 1;
                q.push(e->v);
            }
        }
        return ~t->d;
    }
    LL dfs(Node *u, LL a) {
        if (u == t || !a) return a;
        LL flow = 0;
        for (auto &e : *u) {
            if (u->d + 1 != e->v->d)
                continue;
            LL f = dfs(e->v, min(e->c, a));
            e->c -= f; e->r->c += f;
            flow += f; a -= f;
        }
        return flow;
    }
    void solve(int r, int c) {
        int idx = 1;
        for (int i = 0 ; i < r ; i++) {
            for (int j = 0 ; j < c ; j++) {
                cout << _memE[idx].c + 1 << " \n"[j == c - 1];
                idx += 2;
            }
        }
    }
};
int main() {
    int t, kase = 0; cin >> t; while (t--) {
        cout << "Matrix " << ++kase << '\n';
        int r, c; cin >> r >> c;
        Graph *sol = new Graph(r + c + 2);
        for (int i = 0 ; i < r ; i++)
            for (int j = 0 ; j < c ; j++)
                sol->addEdge(i + 1, j + r + 1, 19);
        int pre = 0;
        for (int i = 0 ; i < r ; i++) {
            int num; cin >> num;
            sol->addEdge(0, i + 1, num - pre - c);
            pre = num;
        }
        pre = 0;
        for (int i = 0 ; i < c ; i++) {
            int num; cin >> num;
            sol->addEdge(i + r + 1, c + r + 1, num - pre - r);
            pre = num;
        }
        sol->maxFlow(0, r + c + 1);
        sol->solve(r, c);
        if (t) cout << '\n';
        delete sol;
    }


}
