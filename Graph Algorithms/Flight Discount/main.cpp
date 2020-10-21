#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 1e5 + 100;
const long long maxD = 1e16 + 100;

struct UWS {
    int u;
    long long w;
    bool s;

    UWS(int _u = 0, long long _w = 0, bool _s = 0) 
    :u(_u), w(_w), s(_s) {}

    bool operator<(const UWS& other) const & {
        return w > other.w;
    }
};

int n, m;
vector<UWS> a[maxN];

long long d[maxN][2];
priority_queue<UWS> q;

void dijkstra() {
    for (int i = 1; i <= n; ++i) 
        d[i][0] = d[i][1] = maxD;
    d[1][0] = d[1][1] = 0;
    q.emplace(1, 0ll, 0);
    q.emplace(1, 0ll, 1);


    while (!q.empty()) {
        auto u = q.top();
        q.pop();
        if (d[u.u][u.s] != u.w) continue;

        for (auto v: a[u.u]) {
            if (d[v.u][u.s] > u.w + v.w) {
                d[v.u][u.s] = u.w + v.w;
                q.emplace(v.u, d[v.u][u.s], u.s);
            }

            if (!u.s && d[v.u][1] > u.w + v.w/2) {
                d[v.u][1] = u.w + v.w/2;
                q.emplace(v.u, d[v.u][1], 1); }
        }
    }
};

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        long long w;
        cin >> x >> y >> w;
        a[x].emplace_back(y, w);
        // a[y].emplace_back(x, w);
    }

    dijkstra();

    cout << d[n][1] << '\n';
}
