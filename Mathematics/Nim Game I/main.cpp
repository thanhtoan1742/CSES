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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        int a = 0;
        while (n--) {
            int x;
            cin >> x;
            a ^= x;
        }

        if (a)
            cout << "first\n";
        else 
            cout << "second\n";
    }
}
