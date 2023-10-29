#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the greatest common divisor (GCD) of two numbers
long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to add two fractions
pair<long long, long long> addFractions(pair<long long, long long> a, pair<long long, long long> b)
{
    long long numerator = a.first * b.second + b.first * a.second;
    long long denominator = a.second * b.second;
    long long commonFactor = gcd(numerator, denominator);
    return make_pair(numerator / commonFactor, denominator / commonFactor);
}

// Function to multiply two fractions
pair<long long, long long> multiplyFractions(pair<long long, long long> a, pair<long long, long long> b)
{
    long long numerator = a.first * b.first;
    long long denominator = a.second * b.second;
    long long commonFactor = gcd(numerator, denominator);
    return make_pair(numerator / commonFactor, denominator / commonFactor);
}

// Function to calculate the probability of getting a sum of n using t dice
pair<long long, long long> probabilityOfSum(int n, int t)
{
    vector<vector<pair<long long, long long>>> dp(t + 1, vector<pair<long long, long long>>(n + 1, make_pair(0, 1)));
    dp[0][0] = make_pair(1, 1);

    for (int i = 1; i <= t; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            for (int k = j; k <= n; k++)
            {
                dp[i][k] = addFractions(dp[i][k], dp[i - 1][k - j]);
            }
        }
    }

    return dp[t][n];
}

// Function to calculate the probability of getting a sum of n using t dice, averaged over all possible values of t
pair<long long, long long> averageProbabilityOfSum(int n, int k)
{
    pair<long long, long long> totalProbability = make_pair(0, 1);

    for (int t = 1; t <= k; t++)
    {
        pair<long long, long long> waysToGetN = probabilityOfSum(n, t);
        totalProbability = addFractions(totalProbability, multiplyFractions(make_pair(1, k), waysToGetN));
    }

    return totalProbability;
}

int main()
{
    int n, k;
    cin >> n >> k;

    pair<long long, long long> result = averageProbabilityOfSum(n, k);

    cout << result.first << "/" << result.second << endl;

    return 0;
}