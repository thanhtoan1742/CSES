#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 1e5 + 100;

int n, m;
vector<int> adj[maxN];

bool visited[maxN];

vector<int> head;

void dfs(int u) {
    visited[u] = 1;
    for (int v: adj[u])
        if (!visited[v]) dfs(v);
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

    for (int i = 1; i <= n; ++i)
        if (!visited[i]) {
            head.push_back(i);
            dfs(i);
        }

    cout << head.size() - 1 << '\n';
    for (int i = 1; i < head.size(); ++i)
        cout << head[i - 1] << ' ' << head[i] << '\n';

