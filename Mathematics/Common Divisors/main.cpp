#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))

using namespace std;
using namespace __gnu_pbds;

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// int n;
// int a[maxN];
// 
// int fp[maxA];
// 
// int f[maxA];
// 
// void seive() {
    // fp[1] = 1;
    // for (int i = 2; i < maxA; ++i)
        // if (!fp[i])
            // for (int j = i; j < maxA; j += i)
                // fp[j] = i;
// }
// 
// void make_d(int u, vector<int>& d) {
    // if (u == 1) {
        // d.push_back(u);
        // return;
    // }
// 
    // int c = 0;
    // int v = u;
    // while (v % fp[u] == 0) {
        // ++c;
        // v /= fp[u];
    // }
// 
    // make_d(v, d);
// 
    // int os = d.size();
    // int p = fp[u];
    // while (c--) {
        // for (int i = 0; i < os; ++i)
            // d.push_back(p*d[i]);
        // p *= fp[u];
    // }
// 
// }
// 
// int solve() {
    // for (int i = 0; i < n; ++i) {
        // vector<int> d;
        // make_d(a[i], d);
// 
        // for (int e: d)
            // ++f[e];
    // }
// 
    // int res = 1;
    // for (int i = 1; i < maxA; ++i)
        // if (f[i] > 1)
            // res = i;
        // 
    // return res;
// }
// 
// int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
// 
    // seive();
    // 
    // cin >> n;
    // for (int i = 0; i < n; ++i)
        // cin >> a[i];
// 
    // cout << solve();
// }
//

const int maxA = 1e6 + 100;
int c[maxA];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        c[a]++;
    }

    for (int i = maxA - 1; i; --i) {
        int d = 0;
        for (int j = i; j < maxA; j += i)
            d += c[j];         

        if (d > 1) {
            cout << i << '\n';
            break;
        }
    }

}
