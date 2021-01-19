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

void print_ans(int n, string& s) {
    if (n == 0) {
        cout << s << '\n';
        return;
    }

    print_ans(n - 1, s);

    if (s[n - 1] == '0')
        s[n - 1] = '1';
    else 
        s[n - 1] = '0';
    print_ans(n - 1, s);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    string s = "";
    for (int i = 0; i < n; ++i)
        s += "0";
    print_ans(n, s);
}
