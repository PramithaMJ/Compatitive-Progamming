#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }

  vector<vector<int>> f(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      f[i][j] = h[i] + h[j];
      for (int k = i + 1; k <= j; k++) {
        f[i][j] += h[k];
      }
    }
  }

  for (int i = 0; i < m; i++) {
    int l, r, c;
    cin >> l >> r >> c;
    l--;
    r--;

    int minK = 1000000000;
    for (int k = 1; k <= 1000000; k++) {
      bool found = false;
      for (int i = l; i <= r; i++) {
        if (h[i] <= k && f[i][min(i + k - 1, r)] >= c) {
          found = true;
          break;
        }
      }

      if (found) {
        minK = k;
        break;
      }
    }

    if (minK == 1000000000) {
      cout << -1 << endl;
    } else {
      cout << minK << endl;
    }
  }

  return 0;
}
