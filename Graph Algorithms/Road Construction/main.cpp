#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5 + 100;
const int maxM = 2e5 + 100;

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

int n, m;

int ncc;
int cs[maxN];
int root[maxN];

int max_cs;

int get_root(int u) {
    if (!root[u]) return u;
    return root[u] = get_root(root[u]);
}

void join(int x, int y) {
    --ncc;
    if (cs[x] > cs[y]) {
        root[y] = x;
        cs[x] += cs[y];
        maximize(max_cs, cs[x]);
    }
    else {
        root[x] = y;
        cs[y] += cs[x];
        maximize(max_cs, cs[y]);
    }
}

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    ncc = n;
    for (int i = 1; i <= n; ++i)
        cs[i] = 1;
    max_cs = 1;

    while (m--) {
        int x, y;
        cin >> x >> y;

        x = get_root(x);
        y = get_root(y);
        if (x != y) 
            join(x, y);

        cout << ncc << ' ' << max_cs << '\n';
    }

}
