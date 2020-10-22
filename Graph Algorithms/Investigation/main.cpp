#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5 + 100;
const int base = 1e9 + 7;
const long long maxD = 1e16;

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
vector<UW> a[maxN];

long long d[maxN];
int pc[maxN];
int max_nc[maxN], min_nc[maxN];

priority_queue<UW> q;

void dijkstra() {
    for (int i = 1; i <= n; ++i) 
        d[i] = maxD;

    d[1] = 0;
    pc[1] = 1;

    q.emplace(1, 0);
    while (!q.empty()) {
        auto u = q.top();
        q.pop();
        if (d[u.u] != u.w) continue;

        for (auto v: a[u.u])
            if (u.w + v.w == d[v.u]) {
                pc[v.u] = (pc[u.u] + pc[v.u]) % base;
                maximize(max_nc[v.u], max_nc[u.u] + 1);
                minimize(min_nc[v.u], min_nc[u.u] + 1);
            }
            else if (u.w + v.w < d[v.u]) {
                d[v.u] = u.w + v.w;
                pc[v.u] = pc[u.u];
                max_nc[v.u] = max_nc[u.u] + 1;
                min_nc[v.u] = min_nc[u.u] + 1;
                q.emplace(v.u, d[v.u]);
            }
    }
}

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int rep = 0; rep < m; ++rep) {
        int x, y, w;
        cin >> x >> y >> w;
        a[x].emplace_back(y, w);
    }

    dijkstra();
        
    cout << d[n] << ' ' << pc[n] << ' ' << min_nc[n] << ' ' << max_nc[n] << '\n';
}
