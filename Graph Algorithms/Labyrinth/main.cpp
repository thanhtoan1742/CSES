#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))
#define minimize(a, b) a = min((a), (b))
#define maximize(a, b) a = max((a), (b))

using namespace std;
const int maxN = 1e3 + 100;

int n, m;
string a[maxN];

queue<array<int, 2>> q;
array<int, 2> trace[maxN][maxN];
bool visited[maxN][maxN];

vector<char> path;

bool bfs(int x, int y) {
    visited[x][y] = 1;
    q.push({x, y});
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (a[x][y] == 'B') return true;

        if (x && !visited[x - 1][y] && a[x - 1][y] != '#') {
            visited[x - 1][y] = 1;
            trace[x - 1][y] = {x, y};
            q.push({x - 1, y});
        }

        if (y && !visited[x][y - 1] && a[x][y - 1] != '#') {
            visited[x][y - 1] = 1;
            trace[x][y - 1] = {x, y};
            q.push({x, y - 1});
        }

        if (x < n - 1 && !visited[x + 1][y] && a[x + 1][y] != '#') {
            visited[x + 1][y] = 1;
            trace[x + 1][y] = {x, y};
            q.push({x + 1, y});
        }

        if (y < m - 1 && !visited[x][y + 1] && a[x][y + 1] != '#') {
            visited[x][y + 1] = 1;
            trace[x][y + 1] = {x, y};
            q.push({x, y + 1});
        }
    }
    return false;
}

void retrace() {
    int x, y;
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
        if (a[i][j] == 'B') {
            x = i;
            y = j;
            break;
        }

    while (a[x][y] != 'A') {
        auto [u, v] = trace[x][y];
        if (u - 1 == x) path.push_back('U');
        if (v - 1 == y) path.push_back('L');
        if (u + 1 == x) path.push_back('D');
        if (v + 1 == y) path.push_back('R');
        x = u;
        y = v;
    }
}

int main(int argc, char* argv[]) {
    // cin.tie(nullptr);
    // ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) 
        cin >> a[i];  

    for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
        if (a[i][j] == 'A') 
            if (bfs(i, j)) {
                retrace();
                cout << "YES\n";
                cout << path.size() << '\n';
                for (int i = path.size() - 1; i >= 0; --i) cout << path[i];
                cout << '\n';

                return 0;
            }

    cout << "NO\n";
}
