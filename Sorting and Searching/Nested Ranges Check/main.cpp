#include <bits/stdc++.h>

#define ll long long
#define ar  array

using namespace std;
const int maxN = 2e5 + 100;

int n;
ar<int, 3> a[maxN];

int rc[maxN], rbc[maxN];

bool cmp_rc(ar<int, 3> a, ar<int, 3> b) {
    if (a[0] == b[0])
        return a[1] > b[1];
    else
        return a[0] < b[0];
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }

    sort(a, a + n, cmp_rc);
    int m0 = 2e9;
    for (int i = n - 1; i >= 0; --i) {
        rc[a[i][2]] = a[i][1] >= m0;
        m0 = min(m0, a[i][1]);
    }

    m0 = 0;
    for (int i = 0; i < n; ++i) {
        rbc[a[i][2]] = a[i][1] <= m0;
        m0 = max(m0, a[i][1]);
    }


    for (int i = 0; i < n; ++i)
         cout << rc[i] << ' ';
    cout << '\n';
    for (int i = 0; i < n; ++i)
         cout << rbc[i] << ' ';
    cout << '\n';
}
