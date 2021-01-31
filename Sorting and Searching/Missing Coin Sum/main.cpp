#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))

using namespace std;
using namespace __gnu_pbds;
const int maxN = 2e5 + 100;

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int n;
ll a[maxN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);

    ll s = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > s + 1) {
            cout << s + 1 << '\n';
            return 0;
        }

        s += a[i];
    }
    cout << s + 1 << '\n';
}
