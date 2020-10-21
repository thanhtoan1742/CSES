#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 1000 + 10;

int n, m;
string a[maxN];

bool visited[maxN][maxN];

void dfs(int x, int y) {
    visited[x][y] = true;
    
    if (x && !visited[x - 1][y] && a[x - 1][y] == '.') dfs(x - 1, y);
    if (y && !visited[x][y - 1] && a[x][y - 1] == '.') dfs(x, y - 1);
    if (x < n - 1 && !visited[x + 1][y] && a[x + 1][y] == '.') dfs(x + 1, y);
    if (y < m - 1 && !visited[x][y + 1] && a[x][y + 1] == '.') dfs(x, y + 1);
}

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int res = 0;
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
        if (!visited[i][j] && a[i][j] == '.') {
            ++res;
            dfs(i, j);
        }

    cout << res << '\n';
}
