#include <bits/stdc++.h>
 
using namespace std;
const int maxN = 1e5 + 100;
 
#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))
 
int n, m;
vector<int> adj[maxN];
 
bool vis[maxN];
int h[maxN];
int hr[maxN];
 
vector<int> cc_rt;
 
void dfs(int u) {
    vis[u] = 1;
    hr[u] = h[u];
 
    for (int v: adj[u]) 
        if (!h[v]) {
            h[v] = h[u] + 1;
            dfs(v);
            minimize(hr[u], hr[v]);
        }
        else 
            if (vis[v]) 
                minimize(hr[u], h[v]);
            else 
                minimize(hr[u], hr[v]);
 
    vis[u] = 0;
    if (hr[u] == h[u]) 
        cc_rt.push_back(u);
}
 
int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
 
    cin >> n >> m;
    for (int rep = 0; rep < m; ++rep) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
 
    for (int i = 1; i <= n; ++i)
        if (!h[i]) {
            h[i] = 1;
            dfs(i);
        }
 
    if (cc_rt.size() > 1) {
        cout << "NO\n";
        cout << cc_rt[0] << ' ' << cc_rt.back() << '\n';
    }
    else 
        cout << "YES\n";
 
    // cout << cc_rt.size() << '\n';
    // for (int u: cc_rt)
    //     cout << u  << ' ';
}