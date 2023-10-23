#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

#define N 100
int reluctance[N];
int current[N];
int desired[N];
int cost[N][N];

int minCost(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        cost[i][j] = 0;
      } else {
        cost[i][j] = reluctance[i] + reluctance[j];
      }
    }
  }

  int dp[n][n];
  for (int i = 0; i < n; i++) {
    dp[i][i] = 0;
  }

  for (int l = 2; l <= n; l++) {
    for (int i = 0; i < n - l + 1; i++) {
      int j = i + l - 1;
      dp[i][j] = INT_MAX;
      for (int k = i; k < j; k++) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + cost[i][j]);
      }
    }
  }

  return dp[0][n - 1];
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> reluctance[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> current[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> desired[i];
  }

  cout << minCost(n) << endl;
}