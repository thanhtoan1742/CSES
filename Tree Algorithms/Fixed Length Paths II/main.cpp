#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ios>
 
#define ll long long
#define ar array
#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))
#define gb(a, n) (((a) >> (n))&1)

const int maxN = 2e5 + 100;
 
using namespace std;
using namespace __gnu_pbds;
template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct block{
    static int size;
    int offset;
    vector<ar<int, 2>> a;

    block(int len = block::size)
    : offset(0), a(len) {
        for (int i = 0; i < a.size(); ++i) {
            a[i][0] = 0;
            a[i][1] = i;
        }
    }

    void update(int val, int l = 0, int r = size - 1) {
        if (l == 0 && r == size - 1) {
            offset += val;
            return;
        }

        for (int i = 0; i < a.size(); ++i) {
            a[i][0] += offset;
            if (l <= a[i][1] && a[i][1] <= r)
                a[i][0] += val;
        }

        offset = 0;
        sort(a.begin(), a.end());
    }

    int get(int val, int l = 0, int r = size - 1) {
        if (l == 0 && r == size - 1) {
            ar<int, 2> t = {val - offset, maxN};
            return upper_bound(a.begin(), a.end(), t) - a.begin();
        }

        update(0);
        int res = 0;
        for (int i = 0; i < a.size(); ++i)
            if (l <= a[i][1] && a[i][1] <= r && a[i][0] <= val)
                ++res;
        return res;
    }
};
int block::size = 0;

int n;
int k1, k2;
vector<int> adj[maxN];

int pos = 1;
int b[maxN], e[maxN];

vector<block> blk;
ll res;
 
void add(int l, int r, int val) {
    l--; r--;
    int bl = l/block::size;
    int br = r/block::size;
    l %= block::size;
    r %= block::size;

    if (bl == br) {
        blk[bl].update(val, l, r);
        return;
    }

    blk[bl].update(val, l, block::size - 1);
    blk[br].update(val, 0, r);
    for (int i = bl + 1; i < br; ++i)
        blk[i].update(val);
}

int get(int l, int r, int val) {
    l--; r--;
    int bl = l/block::size;
    int br = r/block::size;
    l %= block::size;
    r %= block::size;

    if (bl == br) {
        return blk[bl].get(val, l, r);
    }

    int s = 0;
    s += blk[bl].get(val, l, block::size - 1);
    s += blk[br].get(val, 0, r);
    for (int i = bl + 1; i < br; ++i)
        s += blk[i].get(val);
    return s;
}

void DFS(int u = 1, int p = 0) {
    b[u] = e[u] = pos++;

    if (b[u] > 1) {
        // qu.emplace_back(1, 1, b[u] - 1, 1);
        add(1, b[u] - 1, 1);
        // qu.emplace_back(0, 1, b[u] - 1, k1);
        res -= get(1, b[u] - 1, k1);
        // qu.emplace_back(0, 1, b[u] - 1, k2);
        res += get(1, b[u] - 1, k2);
    }

    for (int v: adj[u]) {
        if (v == p)
            continue;

        DFS(v, u);
        e[u] = e[v];
    }

    if (b[u] > 1) {
        // qu.emplace_back(1, b[u], e[u], 1);
        add(b[u], e[u], 1);
        // qu.emplace_back(1, 1, b[u] - 1, -1);
        add(1, b[u] - 1, -1);
    }
}


int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k1 >> k2;
    k1--;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    block::size = sqrt(n);
    for (int i = 0, sz = n; sz; ++i) {
        int len = min(sz, block::size);
        sz -= len;
        blk.emplace_back(len);
    }
    ll res = 0;
    DFS();

    cout << res << "\n";
}