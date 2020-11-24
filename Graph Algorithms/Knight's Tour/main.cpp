#include <bits/stdc++.h>

using namespace std;
const int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

#define maximize(a, b) (a) = max((a), (b))
#define minimize(a, b) (a) = min((a), (b))
#define sqr(x) ((x)*(x))

int vis[8][8];
int cm;

void print_board() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j)
            cout << vis[i][j] << ' ';
        cout <<'\n';
    }
}

bool backtrack(int x, int y) {
    vis[x][y] = ++cm;
    if (cm == 64) {
        print_board();
        return 1;
    }


    for (int i = 0; i < 8; ++i) {
        int u = x + dx[i];
        int v = y + dy[i];
        if (u >= 0 && v >= 0 && u < 8 && v < 8 && !vis[u][v]) 
            if (backtrack(u, v))
                return 1;
    }

    --cm;
    vis[x][y] = 0;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int sx, sy;
    cin >> sx >> sy;
    swap(sx, sy);
    --sx; --sy;
    backtrack(sx, sy);
}