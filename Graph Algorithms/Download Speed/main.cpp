#include <bits/stdc++.h>
 
using namespace std;
const int maxN = 500 + 100;
const int maxM = 1000 + 100;
const int maxFlow = 2e9;
 
#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))
 
struct Edge {
    int u, v, c, f;
 
    Edge(int _u = 0, int _v = 0, int _c = 0, int _f = 0)
    : u(_u), v(_v), c(_c), f(_f) {
    }
};
 
int n, m;
Edge e[maxM];
vector<int> adj[maxN];
 
int lev[maxN];
 
bool find_flow() {
    fill(lev + 1, lev + 1 + n, 0);
    lev[1] = 1;
    queue<int> q;
    q.push(1);
 
    // cout << "find flow:\n";
    while (q.size()) {
        int u = q.front();
        q.pop();
        // cout << "u: " << u << '\n';
 
        if (u == n)
            return true;
 
        for (int i: adj[u]) {
            if (i > 0 && e[i].f < e[i].c && !lev[e[i].v]) {
                lev[e[i].v] = lev[u] + 1;
                q.push(e[i].v);
            }
 
            if (i < 0 && e[-i].f > 0 && !lev[e[-i].u]) {
                lev[e[-i].u] = lev[u] + 1;
                q.push(e[-i].u);
            }
        }
    }
 
    return false;
}
 
int add_flow(int u, int resource) {
    // cerr << u << '\n';
    if (u == n) 
        return resource;
 
    int flow = 0;
    for (int i: adj[u]) {
        int t = 0;
        if (i > 0 && lev[u] + 1 == lev[e[i].v]) {
            t = add_flow(e[i].v, min(resource, e[i].c - e[i].f));
            e[i].f += t;
        }
 
        if (i < 0 && lev[u] + 1 == lev[e[-i].u]) {
            t = add_flow(e[-i].u, min(resource, e[-i].f));
            e[-i].f -= t;
        }
 
        resource -= t;
        flow += t;
    }
 
    return flow;
}
 
long long max_flow() {
    long long flow = 0;
 
    while (find_flow()) 
        flow += add_flow(1, maxFlow);        
 
    return flow;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> e[i].u >> e[i].v >> e[i].c;
        e[i].f = 0;       
 
        adj[e[i].u].push_back(i);
        adj[e[i].v].push_back(-i);
    }
 
    cout << max_flow() << '\n';
}