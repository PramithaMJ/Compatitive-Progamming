#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int N, M, K, B;
        cin >> N >> M >> K >> B;
        vector<vector<int> > grid(N, vector<int>(M));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> grid[i][j];
            }
        }

        vector<vector<int> > max_ice(N, vector<int>(M, -INF));
        vector<vector<int> > consecutive_bad(N, vector<int>(M, 0));

        max_ice[0][0] = grid[0][0];
        consecutive_bad[0][0] = (grid[0][0] < B) ? 1 : 0;

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                if (i > 0)
                {
                    if (grid[i][j] < B)
                    {
                        consecutive_bad[i][j] = consecutive_bad[i - 1][j] + 1;
                    }
                    else
                    {
                        consecutive_bad[i][j] = 0;
                    }
                    if (consecutive_bad[i][j] <= K)
                    {
                        max_ice[i][j] = max(max_ice[i][j], max_ice[i - 1][j] + grid[i][j]);
                    }
                }

                if (j > 0)
                {
                    if (grid[i][j] < B)
                    {
                        consecutive_bad[i][j] = max(consecutive_bad[i][j], consecutive_bad[i][j - 1] + 1);
                    }
                    else
                    {
                        consecutive_bad[i][j] = max(consecutive_bad[i][j], 0);
                    }
                    if (consecutive_bad[i][j] <= K)
                    {
                        max_ice[i][j] = max(max_ice[i][j], max_ice[i][j - 1] + grid[i][j]);
                    }
                }
            }
        }

        if (max_ice[N - 1][M - 1] == -INF)
        {
            cout << "Case " << t << ": IMPOSSIBLE" << endl;
        }
        else
        {
            cout << "Case " << t << ": " << max_ice[N - 1][M - 1] << endl;
        }
    }
    return 0;
}