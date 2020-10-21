#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 1e5 + 100;

int n, m;
vector<int> adj[maxN];

int d[maxN];
queue<int> q;

int trace[maxN];
vector<int> path;

void bfs() {
    for (int i = 1; i <= n; ++i) d[i] = n + 1;
    d[1] = 1;

    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
            if (d[v] == n + 1) {
                d[v] = d[u] + 1;
                trace[v] = u;
                q.push(v);
            }
    }
}

void trace_back() {
    int u = n;
    while (u != 1) {
        path.push_back(u);
        u = trace[u];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
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

    bfs();
    if (d[n] == n + 1) 
        cout << "IMPOSSIBLE\n";
    else {
        trace_back();
        cout << path.size() << '\n';
        for (int u: path) cout << u << ' ';
    }
}
