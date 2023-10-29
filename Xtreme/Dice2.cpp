#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


pair<long long, long long> toFraction(double decimal)
{
    long long precision = 1e6; // Adjust precision as needed
    long long numerator = round(decimal * precision);
    long long denominator = precision;
    long long commonFactor = gcd(numerator, denominator);
    return make_pair(numerator / commonFactor, denominator / commonFactor);
}

int countWaysToGetSum(int n, int t)
{
    vector<vector<long long> > dp(t + 1, vector<long long>(n + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= t; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            for (int k = j; k <= n; k++)
            {
                dp[i][k] += dp[i - 1][k - j];
            }
        }
    }

    return dp[t][n];
}

double probabilityOfSum(int n, int k)
{
    double totalProbability = 0.0;

    for (int t = 1; t <= k; t++)
    {
        long long waysToGetN = countWaysToGetSum(n, t);
        totalProbability += (1.0 / k) * (waysToGetN / pow(6, t));
    }

    return totalProbability;
}

long long calculate(long long p, long long q)
{
    long long mod = 998244353, expo;
    expo = mod - 2;


    while (expo)
    {
        if (expo & 1)
        {
            p = (p * q) % mod;
        }
        q = (q * q) % mod;

        expo >>= 1;
    }
    return p;
}


int main()
{
    int n, k;
    cin >> n >> k;

    double result = probabilityOfSum(n, k);

    cout.precision(10);

    pair<long long, long long> fraction = toFraction(result);
   // cout << fraction.first << "/" << fraction.second << endl;

     cout << calculate(fraction.first, fraction.second) << '\n';
    // cout << calculate(7, 108) << '\n';
    return 0;
}
