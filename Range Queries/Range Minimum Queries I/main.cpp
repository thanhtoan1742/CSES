#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5 + 100;
const int maxA = 1e9 + 100;

#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))

int n, q;
int a[maxN];

int it[maxN*4];

void make_IT(int i = 0, int l = 1, int r = n) {
    if (l == r) {
        it[i] = a[l];
        return;
    }

    int m = (l + r)/2;
    make_IT(2*i + 1, l, m);
    make_IT(2*i + 2, m + 1, r);
    it[i] = min(it[2*i + 1], it[2*i + 2]);
}   

int get_IT(int u, int v, int i = 0, int l = 1, int r = n) {
    if (u <= l && r <= v) 
        return it[i];

    if  (v < l || r < u)
        return maxA;

    int m = (l + r)/2;
    return min(
        get_IT(u, v, 2*i + 1, l, m),
        get_IT(u, v, 2*i + 2, m + 1, r)
    );
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    make_IT();

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << get_IT(l, r) << '\n';
    }
}