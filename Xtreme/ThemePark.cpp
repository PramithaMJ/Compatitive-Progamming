#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, d;
        cin >> n >> d;

        map<string, int> rideCost;
        for (int i = 0; i < n * (n - 1); i++)
        {
            string ride1, ride2;
            int cost;
            cin >> ride1 >> ride2 >> cost;
            rideCost[ride1 + ride2] = cost;
        }

        vector < vector<vector<int>> dp(d + 1, vector < vector<int>(n, vector<int>(n, 0)));

        for (int k = 1; k <= d; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i != j)
                    {
                        dp[k][i][j] = rideCost[ride1 + ride2] + dp[k - 1][j][i];
                    }
                }
            }
        }

        int maxTickets = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                maxTickets = max(maxTickets, dp[d][i][j]);
            }
        }

        cout << maxTickets << endl;
    }

    return 0;
}
