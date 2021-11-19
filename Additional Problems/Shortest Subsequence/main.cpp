#include <bits/stdc++.h>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))
#define gb(a, n) (((a) >> (n))&1)

using namespace std;
using namespace __gnu_pbds;

template<class T>
using indexed_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;
using ll = long long;


const int maxN = 1e6 + 100;
const char alp[] = {'A', 'C', 'G', 'T'};

string solve(string str) {
    bool mark[256];
    fill(mark, mark + 256, 0);
    mark['A'] = mark['C'] = mark['G'] = mark['T'] = 1;


    string res;
    int cm = 0;
    int l = 0;
    for (char c: str) {
        cm += mark[c];
        mark[c] = 0;
        if (cm == 4) {
            res += c;
            mark['A'] = mark['C'] = mark['G'] = mark['T'] = 1;
            cm = 0;
            ++l;
        }
    }

    char c = find_if(mark, mark + 256, [](bool a){return a;}) - mark;
    res += c;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    cin >> str;
    cout << solve(str);
}
