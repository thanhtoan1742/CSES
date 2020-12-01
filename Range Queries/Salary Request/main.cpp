#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
const int maxN = 2e5 + 100;

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))

// struct Query {
//     bool change;
//     int x, y;
// };

// int n, m;
// int a[maxN];
// Query q[maxN*2];

// vector<int> v;

// int fen[maxN*3];

// void add_fenwick(int i, int val) {
//     for (; i <= n + 2*m; i += i & -i)
//         fen[i] += val;
// }

// int get_fenwick(int i) {
//     int res = 0;
//     for (; i ; i &= i - 1)
//         res += fen[i];
//     return res;
// }

// int get_compressed_value(int a) {
//     return lower_bound(v.begin(), v.end(), a) - v.begin() + 1;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

//     cin >> n >> m;
//     v.reserve(n + m*2);
//     for (int i = 0; i < n; ++i) {
//         cin >> a[i];
//         v.push_back(a[i]);
//     }
//     for (int i = 0; i < m; ++i) {
//         char c;
//         cin >> c >> q[i].x >> q[i].y;
//         q[i].change = (c == '!');

//         v.push_back(q[i].y);
//         if (q[i].change)
//             --q[i].x;
//         else 
//             v.push_back(q[i].x);
//     }

//     sort(v.begin(), v.end());
//     for (int i = 0; i < n; ++i) {
//         int j = get_compressed_value(a[i]);
//         add_fenwick(j, 1);
//     }

//     for (int i = 0; i < m; ++i) 
//         if (q[i].change) {
//             int j = get_compressed_value(a[q[i].x]);
//             add_fenwick(j, - 1);
//             j = get_compressed_value(q[i].y);
//             add_fenwick(j, 1);
//             a[q[i].x] = q[i].y;
//         }
//         else {
//             int l = get_compressed_value(q[i].x) - 1;
//             int r = get_compressed_value(q[i].y);
//             cout << get_fenwick(r) - get_fenwick(l) << '\n';
//         }
// }

int n, m;
int a[maxN];

indexed_set<array<int, 2>> iset;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        iset.insert({a[i], i});
    }

    for (int i = 0; i < m; ++i) {
        char q;
        int x, y;
        cin >> q >> x >> y;

        if (q == '!') {
            --x;

            auto it = iset.find({a[x], x});
            iset.erase(it);
            a[x] = y;
            iset.insert({a[x], x});
        }
        else 
            cout << iset.order_of_key({y, n}) - iset.order_of_key({x - 1, n}) << '\n';
    }
}