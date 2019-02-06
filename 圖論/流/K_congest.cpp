#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 3e4 + 5;
const int MAXM = 5e5 + 5;
struct Dinic{
    struct Node; struct Edge;
    int V;
    struct Node : vector<Edge*>{
        iterator cur; int d;
        Node(){ clear(); }
    }_memN[MAXN], *node[MAXN];
    struct Edge{
        Node *u, *v; 
        Edge *rev;
        LL c, f;
        Edge(){}
        Edge(Node *u, Node *v, LL c, Edge *rev) : u(u), v(v), c(c), f(0), rev(rev){}
    }_memE[MAXM], *ptrE;
    Dinic(int _V) : V(_V) {
        for (int i = 0 ; i < V ; i++)
            node[i] = _memN + i;
        ptrE = _memE;
    }
    void addEdge(int _u, int _v, LL _c){
        *ptrE = Edge(node[_u], node[_v], _c, ptrE + 1);
        node[_u]->PB(ptrE++);
        *ptrE = Edge(node[_v], node[_u], 0, ptrE - 1); //  有向: 0, 無向: _c
        node[_v]->PB(ptrE++);
    }
    
    Node *s, *t;
    LL maxFlow(int _s, int _t){
        s = node[_s], t = node[_t];
        LL flow = 0;
        while (bfs()) {
            for (int i = 0 ; i < V ; i++)
                node[i]->cur = node[i]->begin();
            flow += dfs(s, INF);
        }
        return flow;
    }
    bool bfs(){
        for (int i = 0 ; i < V ; i++) node[i]->d = -1;
        queue<Node*> q; q.push(s); s->d = 0;
        while (q.size()) {
            Node *u = q.front(); q.pop();
            for (auto e : *u) {
                Node *v = e->v;
                if (!~v->d && e->c > e->f)
                    q.push(v), v->d = u->d + 1;
            }
        }
        return ~t->d;
    }
    LL dfs(Node *u, LL a){
        if (u == t || !a) return a;
        LL flow = 0, f;
        for (; u->cur != u->end() ; u->cur++) {
            auto &e = *u->cur; Node *v = e->v;
            if (u->d + 1 == v->d && (f = dfs(v, min(a, e->c - e->f))) > 0) {
                e->f += f; e->rev->f -= f;
                flow += f; a -= f;
                if (!a) break;
            }
        }
        return flow;
    }
};
typedef struct Edge {
    int v; LL w;
    bool operator > (const Edge &rhs) const {
        return w > rhs.w;
    }
} State;
typedef pair<int, int> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, c; cin >> n >> m >> c;
    vector<vector<Edge> > G(n);
    map<pii, LL> wei;
    map<pii, LL> cnt;
    while (m--) {
        int u, v; LL w; cin >> u >> v >> w;
        u--, v--;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
        if (v < u) swap(u, v);
        
    }
    priority_queue<State, vector<State>, greater<State> > pq;
    vector<LL> d(n, INF); d[0] = 0; pq.push({0, d[0]});
    while (pq.size()) {
        auto p = pq.top(); pq.pop();
        int u = p.v;
        if (d[u] < p.w) continue;
        for (auto &e : G[u]) {
            if (d[e.v] > d[u] + e.w) {
                d[e.v] = d[u] + e.w;
                pq.push({e.v, d[e.v]});
            }
        }
    }
    map<LL, vector<LL> > q;
    while (c--) {
        int s; cin >> s; s--;
        if (!q.count(d[s]))
            q[d[s]].clear(), q[d[s]].resize(n, 0);
        q[d[s]][s]++;
    }
    LL ans = 0;
    for (auto &p : q) {
        Dinic *sol = new Dinic(n + 1);
        for (int u = 0 ; u < n ; u++) {
            for (auto &e : G[u]) {
                if (d[e.v] != d[u] + e.w)
                    continue;
                sol->addEdge(e.v, u, 1);
            }
            sol->addEdge(n, u, p.second[u]);
        }
        ans += sol->maxFlow(n, 0);
        delete sol;
    }
    cout << ans << '\n';
}
