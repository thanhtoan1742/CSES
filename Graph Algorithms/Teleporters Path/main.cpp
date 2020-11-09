#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5 + 100;

#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))
#define sqr(x) ((x)*(x))

int n, m;
vector<int> adj[maxN];

vector<int> path;
int dd[maxN];

void DFS(int u) {   
    while (!adj[u].empty()) {
        int v = adj[u].back();
        adj[u].pop_back();

        dd[u]--;
        dd[v]++;
        DFS(v);
        path.push_back(u);
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

    path.push_back(n);
    DFS(1);

    if (*max_element(dd + 2, dd + n) || dd[1] != -1 || dd[n] != 1 || (int)path.size() != m + 1) 
        cout << "IMPOSSIBLE\n";
    else {
        reverse(path.begin(), path.end());
        for (int u: path)
            cout << u << ' ';
        cout << '\n';
    }
}