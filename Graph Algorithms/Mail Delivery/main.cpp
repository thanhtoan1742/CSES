#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5 + 100;
const int maxM = 2e5 + 100;

#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))
#define sqr(x) ((x)*(x)) 

struct UI {
    int u, i;
};

int n, m;
vector<UI> adj[maxN];
int deg[maxN];

bool vis[maxM];

vector<int> path;

void DFS(int u) {
    while (!adj[u].empty()) {
        auto v = adj[u].back();
        adj[u].pop_back();

        if (vis[v.i]) continue;
        
        vis[v.i] = true;
        DFS(v.u);
        path.push_back(u);
    }
}

bool have_euler_cycle() {
    for (int i = 1; i <= n; ++i)
        if (deg[i]&1)
            return false;

    return path.size() == m + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back({y, i});
        adj[y].push_back({x, i});
        ++deg[x];
        ++deg[y];
    }


    path.push_back(1);
    DFS(1);  

    if (!have_euler_cycle())
        cout << "IMPOSSIBLE";
    else 
        for (int u: path)
            cout << u << ' ';
}