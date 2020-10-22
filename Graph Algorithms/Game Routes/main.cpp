#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5 + 100;
const int base = 1e9 + 7;

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

void dp(int v) {
    if (visited[v]) return;
    visited[v] = true;
    if (v == 1) {
        f[v] = 1;
        return;
    }

    for (int u: a[v]) {
        dp(u);
        f[v] = (f[v] + f[u]) % base;
    }
}

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int rep = 0; rep < m; ++rep) {
        int x, y;
        cin >> x >> y;
        a[y].push_back(x);
    }    

    dp(n);

    cout << f[n] << '\n';
}
