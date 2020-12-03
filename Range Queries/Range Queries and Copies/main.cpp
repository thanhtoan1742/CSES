#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
const int maxN = 2e5 + 100;
const int maxM = 2e5 + 100;

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))

struct Query {
    int type;
    int u, v, i;
};

int n, m;
int a[maxN];
vector<Query> q[maxM];

stack<Query> qu;
int rollback[maxM];

long long fen[maxN];
stack<int> st;

vector<pair<int, long long>> res;

void add_fenwick(int i, int val) {
    for (; i <= n; i += i & -i)
        fen[i] += val;
}

long long get_fenwick(int i) {
    long long res = 0;
    for (; i; i &= i - 1)
        res += fen[i];
    return res;
}

void init_array() {
    for (int i = 1; i <= n; ++i)
        add_fenwick(i, a[i]);
}

void set_array(int i, int val) {
    add_fenwick(i, val - a[i]);
    a[i] = val;
}

long long get_sum(int l, int r) {
    return get_fenwick(r) - get_fenwick(l - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int ca = 1;
    for (int i = 0; i < m; ++i) {
        int o, k;
        cin >> o >> k;

        if (o == 3) 
            q[k].push_back({o, ++ca, 0, i});
        else {
            int u, v;
            cin >> u >> v;
            q[k].push_back({o, u, v, i});
        }
    }

    init_array();
    rollback[1] = 0;
    st.push(1);

    while (st.size()) {
        int k = st.top();
        st.pop();

        while (qu.size() > rollback[k]) {
            set_array(qu.top().u, qu.top().v);
            qu.pop();
        }

        for (auto que: q[k])
            if (que.type == 1) {
                qu.push({1, que.u, a[que.u], 0});
                set_array(que.u, que.v);
            }
            else if (que.type == 2)
                res.emplace_back(que.i, get_sum(que.u, que.v));
            else {
                rollback[que.u] = qu.size();
                st.push(que.u);
            }
    }

    sort(res.begin(), res.end());
    for (auto r: res)
        cout << r.second << '\n';
}
