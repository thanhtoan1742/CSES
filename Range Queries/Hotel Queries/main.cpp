#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5 + 100;

#define sqr(x) ((x) * (x))
#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))

int n;
int a[maxN];

int it[maxN*4];
int pos[maxN];

void make_IT(int i = 1, int l = 1, int r = n) {
    if (l == r) {
        pos[l] = i;
        it[i] = a[l];
        return;
    }

    int m = (l + r)/2;
    make_IT(2*i, l, m);
    make_IT(2*i + 1, m + 1, r);
    it[i] = max(it[2*i], it[2*i + 1]);
}

void update_IT(int k, int x) {
    a[k] += x;
    it[pos[k]] += x;

    int i = pos[k]/2;
    while (i) {
        it[i] = max(it[2*i], it[2*i + 1]);
        i /= 2;
    }
}

int get_IT(int u, int v, int i = 1, int l = 1, int r = n) {
    if (u <= l && r <= v)
        return it[i];
    if (r < u || v < l)
        return 0;

    int m = (l + r)/2;
    return max(
        get_IT(u, v, 2*i, l, m),
        get_IT(u, v, 2*i + 1, m + 1, r)
    );
}

int get_first_enough(int x) {
    if (get_IT(1, n) < x)
        return 0;

    int l = 1, r = n;
    while (l < r) {
        int m = (l + r)/2;
        if (get_IT(1, m) >= x)
            r = m;
        else 
            l = m + 1;
    }

    return r;
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
        int x;
        cin >> x;

        int i = get_first_enough(x);
        cout << i << '\n';

        if (i)
            update_IT(i, -x);
    }
}