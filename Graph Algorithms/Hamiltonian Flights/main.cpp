#include <bits/stdc++.h>

using namespace std;
const int maxN = 21;
const int base = 1e9 + 7;

#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))
#define sqr(x) ((x)*(x))
#define gb(a, n) (((a) >> (n))&1)

int n, m;
vector<int> adj[maxN];

int f[maxN][1 << maxN];
int res;


void BFS() {
    f[0][1] = 1;

    for (int su = 0; su < (1 << n); ++su) 
        for (int u = 0; u < n; ++u)
            if (gb(su, u)) {
                if (u^(n - 1) && gb(su, n - 1))
                    continue;

                int sv = su ^ (1 << u);
                for (const int v: adj[u])
                    if (gb(sv, v)) {
                        f[u][su] += f[v][sv];
                        if (f[u][su] > base)
                            f[u][su] -= base;
                    }
            }

    res = f[n - 1][(1 << n) - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        // adj[x].push_back(y);
        adj[y].push_back(x);
    }   

    BFS();

    cout << res << '\n';
}