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
const int maxN = 2e6 + 100;

template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

string s, t;

int z[maxN];

void z_fun() {
    int n = s.size();
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) 
            ++z[i];

        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> t;
    s = t + string("#") + s;
    z_fun();

    int res = 0;
    for (int i = 0; i < s.size(); ++i)
        if (z[i] == t.size())
            ++res;

    cout << res << '\n';
}
