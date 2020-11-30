#include <bits/stdc++.h>

using namespace std;
const int maxN = 500 + 100;

#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))

int n, m, k;
vector<int> adj[maxN*2];

bool vis[maxN];

int n_match;
int match[maxN*2];


bool find_match(int u) {
    // cerr << "find_match: u = " << u << ", match[u]: " << match[u] << "\n";
    if (vis[u])
        return 0;
    vis[u] = 1;
    
    for (int v: adj[u]) {
        if (v == match[u])
            continue;

        bool found = !match[v];
        if (!found) 
            found |= find_match(match[v]);

        if (found) {
            match[u] = v;
            match[v] = u;
            return 1;
        }
    }

    return 0;
}

bool find_match() {
    // cerr << "find_match\n";
    fill(vis + 1, vis + 1 + n, 0);
    for (int u = 1; u <= n; ++u)  {
        if (match[u]) 
            continue;

        if (find_match(u))
            return 1;
    }

    return 0;
}

void max_matching() {
    // cerr << "max_matching\n";

    n_match = 0;
    for (int u = 1; u <= n; ++u)
        for (int v: adj[u])
            if (!match[v]) {
                match[u] = v;
                match[v] = u;
                ++n_match;
                break;
            }


    while (find_match())
        ++n_match;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        y += n;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    max_matching();

    cout << n_match << '\n';
    for (int i = 1; i <= n; ++i)
        if (match[i])
            cout << i << ' ' << match[i] - n << '\n';
}