#include <bits/stdc++.h>
 
using namespace std;
const int N = 8;
const int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int vis[N][N];
 
void print_path() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            cout << vis[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
}
 
bool enterable(int u, int v) {
    return u >= 0 && v >= 0 && u < N && v < N && !vis[u][v];
}

int deg(int x, int y) {
    int res = 0;
    for (int i = 0; i < 8; ++i)
        res += enterable(x + dx[i], y + dy[i]);
    return res;
}
 
bool find_path(int x, int y, int i) {
    // cerr << x << ' ' << y << ' ' << i << '\n';
    vis[x][y] = i;
    if (i == N*N) {
        print_path();
        return 1;
    }
 
    vector<int> p(8);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [x, y](int i, int j){
        return deg(x + dx[i], y + dy[i]) < deg(x + dx[j], y + dy[j]);
    });

    for (int j: p) {
        int u = x + dx[j];
        int v = y + dy[j];   

        if (!enterable(u, v))
            continue;

        if (find_path(u, v, i + 1))
            return 1;
    }
 
    vis[x][y] = 0;
    return 0;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int x, y;
    cin >> x >> y;
    find_path(y - 1, x - 1, 1);
}