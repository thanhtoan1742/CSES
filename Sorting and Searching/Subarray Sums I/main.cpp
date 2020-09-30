#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 2e5 + 100;

int n;
long long x;
int a[maxN];

int res;

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) 
        cin >> a[i];


    res = 0;
    long long s = 0;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        s += a[i];
        while (j <= i && s > x)     
            s -= a[j++];
        
        res += s == x;
    }

    cout << res << '\n';
}
