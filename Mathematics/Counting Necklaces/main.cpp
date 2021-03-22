#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define ll long long
#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))
#define gb(a, n) (((a) >> (n))&1)
 
using namespace std;
using namespace __gnu_pbds;
 
template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
int n, m;
int a[20];

int res;

bool check() {
    vector<int> og(a, a + n); 
    vector<int> p = og;

    for (int i = 1; i < n; ++i) {
        p.push_back(p[0]);
        p.erase(p.begin());

        if (p < og)
            return 0;
    }

    return 1;
}

void bf(int i = 0) {
    if (i == n) {
        int t = check();
        res += t;
        if (!t)
            return;

        for (int j = 0; j < n; ++j)
            cout << a[j] << ' ';
        cout << '\n';

        return;
    }

    for (int j = 0; j < m; ++j) {
        a[i] = j;
        bf(i + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 

    n = 4;
    m = 3;

    res = 0;
    bf();

    cout << res << '\n';

    n = 4;
    a[0] = 0;
    a[1] = 2;
    a[2] = 0;
    a[3] = 0;
}