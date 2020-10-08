#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 5000 + 10;

int n, m;
string a, b;

int f[maxN][maxN];

int dp() {
    for (int i = 0; i <= n; ++i)
        f[i][0] = i;
    for (int j = 0; j <= m; ++j)
        f[0][j] = j;
        
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
        f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1; 
        minimize(f[i][j], f[i - 1][j - 1] + (a[i] != b[j]));
    }

    return f[n][m];
}

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);


    cin >> a; 
    n = a.size(); 
    a = string("#") + a;
    cin >> b;    
    m = b.size();
    b = string("#") + b;

    cout << dp() << '\n';
}
