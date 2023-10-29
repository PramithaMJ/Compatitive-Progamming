#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 998244353;

int main()
{
    int k, n;
    cin >> k >> n;

    vector<vector<long long> > binomial_coefficients(k + 1, vector<long long>(k + 1));
    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (j == 0 || i == j)
            {
                binomial_coefficients[i][j] = 1;
            }
            else
            {
                binomial_coefficients[i][j] = (binomial_coefficients[i - 1][j] + binomial_coefficients[i - 1][j - 1]) % MOD;
            }
        }
    }

   
    vector<long long> answer(1 << k);
    for (int i = 0; i <= k; i++)
    {
        long long power = 1LL << i;
        for (int t = 0; t < (1 << k); t++)
        {
            if (t % power == 0)
            {
                answer[t] = (answer[t] + binomial_coefficients[n][i]) % MOD;
            }
        }
    }


    for (int i = 0; i < (1 << k); i++)
    {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}
