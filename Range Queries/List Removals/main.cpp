// #include <bits/stdc++.h>

// using namespace std;
// const int maxN = 2e5 + 100;

// #define sqr(x) ((x) * (x))
// #define maximize(a, b) (a) = max((a), (b))
// #define minimize(a, b) (a) = min((a), (b))

// int n;
// int a[maxN];

// int fen[maxN]; 

// int get_fenwick(int p) {
//     int res = 0;
//     for (; p ; p &= p - 1)
//         res += fen[p];

//     return res;
// }

// void add_fenwick(int p, int x) {
//     for (; p <= n; p += p & -p)
//         fen[p] += x;
// }

// int get_pos(int p) {
//     int l = 1, r = n;
//     while (l < r) {
//         int m = (l + r)/2;
//         if (get_fenwick(m) < p)
//             l = m + 1;
//         else 
//             r = m;
//     }

//     return r;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

//     cin >> n;
//     for (int i = 1; i <= n; ++i) {
//         cin >> a[i];
//         add_fenwick(i, 1);
//     }

//     for (int i = 1; i <= n; ++i) {
//         int p;
//         cin >> p;
//         int j = get_pos(p);
//         cout << a[j] << '\n';
//         add_fenwick(j, -1);
//     }

// }

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n;
oset<array<int, 2>> os;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        os.insert({i, a});
    }

    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        auto it = os.find_by_order(p - 1);

        cout << (*it)[1] << ' ';
        os.erase(it);
    }
}   