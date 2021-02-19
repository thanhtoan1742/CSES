#include <bits/stdc++.h>

using namespace std;
const int maxN = 500 + 100;
const int maxM = 1000 + 100;

#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))

struct Edge {
    int u, v, irev, c;
};

int n, m;
Edge e[maxM*2];
vector<int> adj[maxN];

int lev[maxN];

vector<int> path;

bool find_flow() {
    fill(lev + 1, lev + 1 + n, 0);
    queue<int> q;
    lev[1] = 1;
    q.push(1);

    while (q.size()) {
        int u = q.front();
        q.pop();

        if (u == n) 
            return 1;

        for (int i: adj[u])
            if (e[i].c && !lev[e[i].v]) {
                lev[e[i].v] = lev[u] + 1;
                q.push(e[i].v);
            }
    }

    return 0; 
}

int add_flow(int u = 1, int inflow = 1e9) {
    if (u == n) {
        return inflow;
    }
    int og_inflow = inflow;

    for (int i: adj[u])
        if (lev[e[i].v] == lev[u] + 1) {
            int t = add_flow(e[i].v, min(inflow, e[i].c));
            e[i].c -= t;
            e[e[i].irev].c += t;
            inflow -= t;
        }

    return og_inflow - inflow;
}

void print_flow_path(int u = 1) {
    if (u == n) {
        cout << path.size() + 1 << '\n';
        for (int u: path) 
            cout << u << ' ';
        cout << n << '\n';

        return;
    }

    path.push_back(u);

    for (int i: adj[u]) 
        if (i < m && !e[i].c) {
            e[i].c = 1;
            e[e[i].irev].c = 1;
            print_flow_path(e[i].v);
            if (u != 1)
                break;
        }

    path.pop_back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        
        e[i] = {x, y, i + m, 1};
        e[i + m] = {y, x, i, 0};
        adj[x].push_back(i);
        adj[y].push_back(i + m);
    }

    int flow = 0;
    while (find_flow())
        flow += add_flow();
    
    cout << flow << '\n';

    print_flow_path();
}
