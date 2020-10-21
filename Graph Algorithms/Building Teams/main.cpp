#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 1e5 + 100;

int n, m;
vector<int> adj[maxN];

bool res;
int g[maxN];

void dfs(int u) {
    for (int v : adj[u]) 
        if (g[v]) {
            if (g[v] == g[u]) res = 0;
        }
        else {
            g[v] = 3 - g[u];
            dfs(v);
        }
}

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }  

    res = 1;
    for (int i = 1; i <= n; ++i)
        if (g[i] == 0) {
            g[i] = 1;
            dfs(i);
        }

    if (res) 
        for (int i = 1; i <= n; ++i) cout << g[i] << ' ';
    else 
        cout << "IMPOSSIBLE";
}
