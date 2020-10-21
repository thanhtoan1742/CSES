#include <bits/stdc++.h>

using namespace std;
const int maxN = 2500 + 100;
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
int tr[maxN];

int s, t;
vector<int> cy;

bool bellman_ford() {
    d[1] = 0;
    for (int i = 2; i <= n; ++i)
        d[i] = maxD;

    for (int rep = 1; rep <= n; ++rep) 
        for (int x = 1; x <= n; ++x) 
            for (auto v: a[x]) 
                if (d[x] + v.w < d[v.u]) {
                    d[v.u] = d[x] + v.w;
                    tr[v.u] = x;
                    
                    if (rep == n) {
                        s = x;
                        t = v.u;
                        return true;
                    }
                }

    return false;
}

void trace_back() {
    int u = s;
    for (int rep = 0; rep < n; ++rep)
        u = tr[u];
        
    s = u;
    do {
        cy.push_back(u);
        u = tr[u];
    }
    while (u != s);
    cy.push_back(u);
    reverse(cy.begin(), cy.end());
}

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        a[x].emplace_back(y, w);
    }  

    if (bellman_ford()) {
        cout << "YES\n";
        trace_back();
        for (int u : cy) 
            cout << u << ' ';
        cout << '\n';
    }
    else {
        cout << "NO\n";
    }
}
