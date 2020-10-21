#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 1e5 + 100;
const long long maxD = 1e18;

typedef tuple<long long, int> DU;

int n, m;
vector<DU> adj[maxN];

priority_queue<DU, vector<DU>, greater<DU>> q;
long long d[maxN];

void dijkstra(int u) {
    for (int i = 1; i <= n; ++i) d[i] = maxD;
    d[u] = 0;
    q.emplace(d[u], u);

    while (!q.empty()) {
        auto [du, u] = q.top();
        q.pop();
        if (d[u] != du) continue;

        for (auto [c, v]:adj[u]) 
            if (d[v] > d[u] + c) {
                d[v] = d[u] + c;
                q.emplace(d[v], v);
            }
    }
}

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    while (m--) {
        int x, y, c;
        cin >> x >> y >> c;
        adj[x].emplace_back(c, y);
    }

    dijkstra(1);
    
    for (int i = 1; i <= n; ++i)
        cout << d[i] << ' ';
}
