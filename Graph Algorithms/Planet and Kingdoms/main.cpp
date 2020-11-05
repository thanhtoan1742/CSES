#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5 + 100;

#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))
#define sqr(x) ((x)*(x))

int n, m;
vector<int> adj[maxN];

int nnum;
int num[maxN], inum[maxN];

bool deleted[maxN];
vector<int> vs;

int rt[maxN];

int ncc;
int cc[maxN];

int get_root(int u) {
    if (!rt[u]) return u;
    return rt[u] = get_root(rt[u]);
}

void dfs(int u) {
    inum[u] = num[u] = nnum++;
    vs.push_back(u);

    for (int v: adj[u]) {
        if (deleted[v]) continue;

        if (!num[v]) {
            num[v] = num[u] + 1;
            rt[v] = u;
            dfs(v);
            minimize(inum[u], inum[v]);
        }
        else 
            minimize(inum[u], num[v]);
    }

    if (inum[u] == num[u]) {
        cc[u] = ++ncc;
        rt[u] = 0;

        do {
            int v = vs.back();
            vs.pop_back();
            deleted[v] = 1;
            if (v == u) break;
        }
        while (true);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }   

    for (int u = 1; u <= n; ++u)
        if (!num[u]) 
            dfs(u);

    cout << ncc << '\n';
    for (int u = 1; u <= n; ++u)
        cout << cc[get_root(u)] << ' ';
    cout << '\n';
}