#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define ll long long
#define ar array
#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))
#define gb(a, n) (((a) >> (n))&1)
 
using namespace std;
using namespace __gnu_pbds;
template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int maxN = 1e6 + 100;

int n;
string a;
int z[maxN], rz[maxN];

void z_func(int z[]) {
    z[0] = 0;
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        z[i] = 0;
        if (i < r)
            z[i] = min(z[i - l], r - i);

        while (i + z[i] < n && a[i + z[i]] == a[z[i]])
            ++z[i];

        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> a;
    n = a.size();
    z_func(z);

    for (int l = 1; l <= n; ++l) {
        int i = n - l;
        if (i + z[i] == n)
            cout << l << " ";
    }
}