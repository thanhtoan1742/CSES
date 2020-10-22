#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5 + 100;

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

struct UW {
    int u;
    long long w;

    UW(int _u = 0, long long _w = 0) 
    : u(_u), w(_w) {}

    bool operator<(const UW& other) const & {
        return w > other.w;
    }
};

int n, m;
vector<int> a[maxN];

int deg[maxN];
int c;

vector<int> res;

void dfs(int u) {
    --deg[u];
    ++c;
    res.push_back(u);

    for (int v: a[u]) {
        --deg[v];
        if (deg[v] == 0)
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
        a[x].push_back(y);
        ++deg[y];
    }

    for (int i = 1; i <= n; ++i)    
        if (deg[i] == 0) dfs(i);

    if (c != n) 
        cout << "IMPOSSIBLE\n";
    else {
        for (int u: res)
            cout << u << ' ';
        cout << '\n';
    }
}
