#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5 + 100;

#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))

int n;
int a[maxN];

long long it[maxN*4];
long long upd[maxN*4];

void make_IT(int i = 1, int l = 1, int r = n) {
    if (l == r) {
        it[i] = a[l];
        return;
    }

    int m = (l + r)/2;
    make_IT(2*i, l, m);
    make_IT(2*i + 1, m + 1, r);
    it[i] = it[2*i] + it[2*i + 1];
}

void push_down_IT(int i) {
    it[2*i] += upd[i];
    upd[2*i] += upd[i];
    it[2*i + 1] += upd[i];
    upd[2*i + 1] += upd[i];

    upd[i] = 0;
}

void update_IT(int u, int v, int x, int i = 1, int l = 1, int r = n) {
    if (u <= l && r <= v) {
        it[i] += x;
        upd[i] += x;
        return;
    }
    if (v < l || r < u)
        return;

    int m = (l + r)/2;
    push_down_IT(i);
    update_IT(u, v, x, 2*i, l, m);
    update_IT(u, v, x, 2*i + 1, m + 1, r);

    it[i] = it[2*i] + it[2*i + 1];
}

long long get_IT(int u, int v, int i = 1, int l = 1, int r = n) {
    if (u <= l && r <= v) 
        return it[i];
    if (v < l || r < u)
        return 0;

    int m = (l + r)/2;
    push_down_IT(i);
    long long res = get_IT(u, v, 2*i, l, m) + get_IT(u, v, 2*i + 1, m + 1, r);

    it[i] = it[2*i] + it[2*i + 1];
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    make_IT();

    while (q--) {
        int o;
        cin >> o;
        if (o == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            update_IT(l, r, x);
        }
        else {
            int k;
            cin >> k;
            cout << get_IT(k, k) << '\n';
        }
    }
}