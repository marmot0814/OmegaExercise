#include <bits/stdc++.h>
#define PB push_back
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 5e2 + 5;
const int MAXM = (MAXN * MAXN) / 2;
struct Graph{
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
    Graph(int _V) : V(_V) {
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
#define F first
#define S second
const double eps = 1e-20;
typedef pair<LL, LL> pii;
bool check(pii a, pii b, pii c) {
    LL dist1 = (a.F - b.F) * (a.F - b.F) + (a.S - b.S) * (a.S - b.S);
    LL dist2 = (c.F - a.F) * (c.F - a.F) + (c.S - a.S) * (c.S - a.S);
    LL dist3 = (c.F - b.F) * (c.F - b.F) + (c.S - b.S) * (c.S - b.S);
    return sqrt(dist1) * 2 - (sqrt(dist2) + sqrt(dist3)) > eps;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n, m; cin >> n >> m;
        Graph *sol = new Graph(n + m + 1);
        vector<pair<LL, LL> > data1(n);
        vector<pair<LL, LL> > data2(m);
        for (auto &p : data1) cin >> p.first >> p.second;
        for (auto &p : data2) cin >> p.first >> p.second;
        int cnt = 0;
        for (int i = 0 ; i < n - 1 ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (check(data1[i], data1[i + 1], data2[j]))
                    sol->addEdge(i + 1, j + n, 1), cnt++;
            }
        }
        for (int i = 0 ; i < n - 1 ; i++)
            sol->addEdge(0, i + 1, 1);
        for (int i = 0 ; i < m ; i++)
            sol->addEdge(i + n, n + m, 1);
        cout << n + sol->maxFlow(0, n + m) << '\n';
        vector<pair<int, int> > res;
        for (int i = 0 ; i < cnt ; i++) {
            if (!sol->_memE[i * 2].f)
                continue;
            res.emplace_back(sol->_memE[i * 2].u - sol->_memN - 1, sol->_memE[i * 2].v - sol->_memN - n);
        }
        vector<int> ans(n - 1, -1);
        for (auto &p : res)
            ans[p.F] = p.S;
        cout << data1[0].F << ' ' << data1[0].S << ' ';
        for (int i = 0 ; i < n - 1 ; i++) {
            if (ans[i] != -1)
                cout << data2[ans[i]].F << ' ' << data2[ans[i]].S << ' ';
            cout << data1[i + 1].F << ' ' << data1[i + 1].S << " \n"[i == n - 2];
        }
        delete sol;
        if (t) cout << '\n';
    }
}
