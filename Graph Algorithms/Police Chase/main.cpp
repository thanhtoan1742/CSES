#include <bits/stdc++.h>

using namespace std;
const int maxN = 500 + 100;
const int maxM = 1000 + 100;
const int maxFlow = maxM + 100;

#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))

struct Edge {
    int u, v, c, f;

    Edge(int _u = 0, int _v = 0, int _c = 0, int _f =0 )
    : u(_u), v(_v), c(_c), f(_f) {
    }
}; 

int n, m;
Edge e[2*maxM];
vector<int> adj[maxN];

int lev[maxN];

bool find_flow() {
    queue<int> q;
    fill(lev + 1, lev + 1 + n, 0);

    lev[1] = 1;
    q.push(1);

    while (q.size()) {
        int u = q.front();
        q.pop();

        if (u == n)
            return 1;

        for (int i: adj[u]) {
            if (i > 0 && !lev[e[i].v] && e[i].f < e[i].c) {
                lev[e[i].v] = lev[u] + 1;
                q.push(e[i].v);
            }

            if (i < 0 && !lev[e[-i].u] && e[-i].f) {
                lev[e[-i].u] = lev[u] + 1;
                q.push(e[-i].u);
            }
        }
    }

    return 0;
}

int add_flow(int u, int flowin) {
    if (u == n)
        return flowin;

    int og_flowin = flowin;

    for (int i: adj[u]) {
        int t = 0;

        if (i > 0 && lev[u] + 1 == lev[e[i].v]) {
            t = add_flow(e[i].v, min(flowin, e[i].c - e[i].f));
            e[i].f += t;
        }

        if (i < 0 && lev[u] + 1 == lev[e[-i].u]) {
            t = add_flow(e[-i].u, min(flowin, e[-i].f));
            e[-i].f -= t;
        }

        flowin -= t;
    }

    return og_flowin - flowin;
}

int max_flow() {
    int flow = 0;

    while (find_flow()) 
        flow += add_flow(1, maxFlow);

    return flow;
}

void s_reach(int u) {
    lev[u] = 1;
    for (int i: adj[u])
        if (i > 0 && e[i].f < e[i].c && !lev[e[i].v])
            s_reach(e[i].v);
}

void print_min_cut() {
    fill(lev + 1, lev + 1 + n, 0);
    s_reach(1);
    
    for (int u = 1; u <= n; ++u)
        if (lev[u])
            for (int i: adj[u])
                if (i > 0 && !lev[e[i].v])
                    cout << u << ' ' << e[i].v << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> e[i].u >> e[i].v;
        e[i].c = 1;
        
        adj[e[i].u].push_back(i);
        adj[e[i].v].push_back(-i);

        e[i + m] = e[i];
        swap(e[i + m].u, e[i + m].v);
        adj[e[i + m].u].push_back(i + m);
        adj[e[i + m].v].push_back(-i - m);
    }

    cout << max_flow() << '\n';
    print_min_cut();
}