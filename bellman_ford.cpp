#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair <int, int>;

struct edges {
  int u, v, w;
};

const int N = 105, inf = 1e9 + 7;

int n, m;
int dist[N];

int main () {
  ios::sync_with_stdio(0); cin.tie(0);
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
#endif
  cin >> n >> m;
  vector <edges> e(m);
  fill(dist, dist + n + 1, inf);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    e[i] = {u, v, w};
  }
  dist[1] = 0;
  for (int i = 1; i <= n; ++i) {
    for (auto [u, v, w] : e) {
      if (dist[u] != inf and dist[v] > dist[u] + w) dist[v] = dist[u] + w;
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << (dist[i] == inf ? 30000 : dist[i]) << " ";
  }
  cout << "\n";
  return 0;
}