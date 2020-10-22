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

bool visiting[maxN];
int tr[maxN];

int s;
vector<int> cy;

bool dfs(int u) {
    visiting[u] = 1;

    for (int v: a[u])
        if (!tr[v]) {
            tr[v] = u;
            auto rv = dfs(v);
            if (rv) return 1;
        }
        else {
            if (!visiting[v]) continue;
            tr[v] = u;
            s = u;
            return 1;
        }

    visiting[u] = 0;
    return 0;
}

void trace_back() {
    int u = s;
    do {
        cy.push_back(u);
        u = tr[u];
    }
    while (u != s);
    cy.push_back(s);
    reverse(cy.begin(), cy.end());
}

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
    }

    for (int i = 0; i < n; ++i)
        if (tr[i] == 0) {
            tr[i] = -1;
            if (dfs(i)) {
                trace_back();
                cout << cy.size() << '\n';
                for (int u: cy)
                    cout << u << ' ';
                cout << '\n';
                return 0;
            }
        }

    cout << "IMPOSSIBLE\n";
}
