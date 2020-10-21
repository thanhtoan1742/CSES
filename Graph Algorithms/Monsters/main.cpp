#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 1000 + 10;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n, m;
string a[maxN];
int xA, yA;

array<int, 2> tr[maxN][maxN];
queue<array<int, 3>> q;

string p;

bool valid(int u, int v) {
    return u >= 0 && v >= 0 && u < n && v < m && a[u][v] != '#';
}

void retrace(int x, int y) {
    while (x^xA || y^yA) {
        auto [u, v] = tr[x][y];
        if (u + 1 == x) p.append("D");
        if (u - 1 == x) p.append("U");
        if (v + 1 == y) p.append("R");
        if (v - 1 == y) p.append("L");

        x = u;
        y = v;
    }
    reverse(p.begin(), p.end());
}

array<int, 2> bfs() {
    int c = 1;
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
        if (a[i][j] == 'A') xA = i, yA = j;
        if (a[i][j] == 'M') q.push({i, j, c++}), a[i][j] = '#';
    }
    q.push({xA, yA, 0});
    a[xA][yA] = '#';

    while (!q.empty()) {
        auto [x, y, c] = q.front();
        q.pop();

        if (c == 0 && (x == 0 || y == 0 || x == n - 1 || y == m - 1)) return {x, y};

        for (int i = 0; i < 4; ++i) {
            int u = x + dx[i];
            int v = y + dy[i];
            if (!valid(u, v)) continue;

            a[u][v] = '#';
            q.push({u, v, c});
            if (c == 0) tr[u][v] = {x, y};
        }
    }

    return {-1, -1};
}

int main(int argc, char* argv[]) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];

    auto [x, y] = bfs();
    if (x == -1) 
        cout << "NO\n";
    else {
        cout << "YES\n";

        retrace(x, y);
        cout << p.size() << '\n';
        cout << p << '\n';
    }
}
