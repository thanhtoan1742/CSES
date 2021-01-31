#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ar array
#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))

using namespace std;
using namespace __gnu_pbds;
const int maxN = 2e5 + 100;

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n, m;
int a[maxN];
int p[maxN];

int res;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        p[a[i]] = i;
    }
    p[0] = -1;
    p[n + 1] = n + 1;

    res = 1;
    for (int i = 2; i <= n; ++i) 
        res += p[i] < p[i - 1];

    while (m--) {
        int i, j;
        cin >> i >> j;
        --i, --j;

        if (a[i] == a[j] + 1 || a[j] == a[i] + 1) {
            int x = min(a[i], a[j]);

            res -= p[x] < p[x - 1];
            res -= p[x + 1] < p[x];
            res -= p[x + 2] < p[x + 1];

            swap(a[i], a[j]);
            p[a[i]] = i;
            p[a[j]] = j;

            res += p[x] < p[x - 1];
            res += p[x + 1] < p[x];
            res += p[x + 2] < p[x + 1];
        }
        else {
            res -= p[a[i]] < p[a[i] - 1];
            res -= p[a[i] + 1] < p[a[i]];
            res -= p[a[j]] < p[a[j] - 1];
            res -= p[a[j] + 1] < p[a[j]];

            swap(a[i], a[j]);
            p[a[i]] = i;
            p[a[j]] = j;

            res += p[a[i]] < p[a[i] - 1];
            res += p[a[i] + 1] < p[a[i]];
            res += p[a[j]] < p[a[j] - 1];
            res += p[a[j] + 1] < p[a[j]];
        }
        cout << res << '\n';
    }

}
