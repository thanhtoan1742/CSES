#include <bits/stdc++.h>
 
using namespace std;
const int maxN = 1e5 + 100;
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
 
int n, m, k;
vector<UW> a[maxN];
 
priority_queue<UW> q;
int path_count[maxN];
 
vector<long long> res;
 
void k_dijkstra() {
    q.emplace(1, 0);
 
    while (!q.empty()) {
        auto u = q.top();
        q.pop();
        if (path_count[u.u] == k) continue;
        ++path_count[u.u];

        if (u.u == n) {
            res.push_back(u.w);
            if (res.size() == k) return;
        }
 
        for (auto v: a[u.u])
            q.emplace(v.u, u.w + v.w);
    }
}
 
 
int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
 
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        a[x].emplace_back(y, w);        
    }        
 
    k_dijkstra();

    for (auto w: res)
        cout << w << ' ';
    cout << '\n';
}