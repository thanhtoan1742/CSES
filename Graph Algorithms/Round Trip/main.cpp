#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 1e5 + 100;

int n, m;
vector<int> adj[maxN];

int cur = 0;
int visited[maxN];
vector<int> path;

bool dfs(int u) {
    visited[u] = cur++;
    path.push_back(u);

    for (int v : adj[u])
        if (visited[v]) {
            if (path.size() - visited[v] >= 3) {
                path.push_back(v);
                return true;
            }
        }
        else {
            if (dfs(v)) return true;
        }

    path.pop_back();
    cur--;
    return false;
}

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 1; i <= n; ++i)
        if (!visited[i]) {
            cur = 0;
            if (dfs(i)) {
                reverse(path.begin(), path.end());
                while (path.back() != path[0]) path.pop_back();
                cout << path.size()<< '\n';
                for (int c : path) cout << c << ' ';
                return 0;
            }
        }
    cout << "IMPOSSIBLE\n";
}
