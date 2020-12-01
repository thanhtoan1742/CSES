#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5 + 100;
const int maxA = 1e9 + 100;

#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))

int n, q;
int a[maxN];

long long it[maxN*4];
int pos[maxN];

void make_IT(int i = 1, int l = 1, int r = n) {
    if (l == r) {
        it[i] = a[l];
        pos[l] = i;
        return;
    }

    int m = (l + r)/2;
    make_IT(2*i, l, m);
    make_IT(2*i + 1, m + 1, r);
    it[i] = it[2*i] + it[2*i + 1];
}

void update_IT(int k, int x) {
    a[k] = x;
    it[pos[k]] = x;

    int i = pos[k]/2;
    while (i) {
        it[i] = it[2*i] + it[2*i + 1];
        i /= 2;
    }
}

long long get_IT(int u, int v, int i = 1, int l = 1, int r = n) {
    if (u <= l && r <= v)
        return it[i];
    if (r < u || v < l)
        return 0;

    int m = (l + r)/2;
    return get_IT(u, v, 2*i, l, m) + get_IT(u, v, 2*i + 1, m + 1, r);
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
        int o, l, r;
        cin >> o >> l >> r;
        if (o == 1) 
            update_IT(l, r);
        else 
            cout << get_IT(l, r) << '\n';
    }
}