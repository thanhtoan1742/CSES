#include <bits/stdc++.h>

#define LP(u) (#u) << ": " << (u) << " "

using namespace std;

using ll = long long;

const int maxN = 510;
const int maxM = 1010;
const ll maxF = 2e15 + 10;

struct Edge {
  int u;
  int v;
  ll c;
  ll uf;
};

int n, m;
Edge e[maxM];
vector<int> eo[maxN];

int pre[maxN];
ll flow[maxN];


ll find_flow() {
  fill(pre, pre + n + 1, 0);
  fill(flow, flow + n + 1, 0);

  queue<int> q;
  q.push(1);
  flow[1] = maxF;
  pre[1] = -1;

  
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    // cout << LP(u) << "\n";

    if (u == n)
      break;

    for (int i: eo[u]) {
      auto [x, y, c, uf] = e[abs(i)];
      int v = (i > 0) ? y : x;
      if (pre[v] != 0)
        continue;

      if (i > 0) {
        if (uf == c)
          continue;
        flow[v] = min(flow[u], c - uf);
      } else {
        if (uf == 0)
          continue;
        flow[v] = min(flow[u], uf);
      }

      pre[v] = i;
      q.push(v);
      // cout << LP(i) << LP(v) << LP(flow[u]) << LP(c) << LP(uf) << LP(flow[v]) << "\n";
    }

  }


  ll res = flow[n];
  if (res == 0)
    return 0;


  int v = n;
  while (v != 1) {
    int i = pre[v];
    if (i > 0) {
      e[i].uf += res;
      v = e[i].u;
    } else {
      e[-i].uf -= res;
      v = e[-i].v;
    }
  }

  return res;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> e[i].u >> e[i].v >> e[i].c;
    e[i].uf = 0;
    eo[e[i].u].push_back(i);
    eo[e[i].v].push_back(-i);
  }

  ll res = 0;
  while (true) {
    ll a = find_flow();
    // cout << LP(a) << "\n";
    // for (int i = 1; i <= m; ++i) cout  << LP(e[i].u) << LP(e[i].v) << LP(e[i].uf) << LP(e[i].c) << "\n";
    if (a == 0)
      break;
    res += a;
  }

  cout << res << "\n";
}
