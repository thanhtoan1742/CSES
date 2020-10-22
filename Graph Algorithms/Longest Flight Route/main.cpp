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

bool visited[maxN];
int f[maxN];
int tr[maxN];

vector<int> res;

void b_dfs(int v) {
    if (visited[v]) return;
    visited[v] = 1;
    if (v == 1) {
        f[v] = 1;
        return;
    }

    for (int u: a[v]) {
        b_dfs(u);

        if (f[u] && f[v] < f[u] + 1) {
            f[v] = f[u] + 1;
            tr[v] = u;
        }
    }
}

void trace_back() {
    int u = n;
    while (u != 0) {
        res.push_back(u);
        u = tr[u];
    }
    reverse(res.begin(), res.end());
}

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        a[y].push_back(x);
    }

    b_dfs(n);

    if (!f[n])
        cout << "IMPOSSIBLE\n";
    else {
        trace_back();
        cout << res.size() << '\n';
        for (int u: res)
            cout << u << ' ';
    }
}
