#include <iostream>
#include <vector>

using namespace std;

long long mod = 1000000009;

// Function to calculate the sequence of allowable values
vector<long long> calculateAllowableValues(int n, long long h0, long long a, long long b, long long q)
{
    vector<long long> sequence;
    sequence.push_back(h0);
    for (int i = 1; i < n; i++)
    {
        long long hi = (a * sequence[i - 1] + b) % q;
        sequence.push_back(hi);
    }
    return sequence;
}

int main()
{
    int c;
    cin >> c;
    while (c--)
    {
        int n;
        long long t, h0, a, b, q;
        cin >> n >> t >> h0 >> a >> b >> q;

        vector<long long> sequence = calculateAllowableValues(n, h0, a, b, q);

        // Check if the target code is reachable from the sequence of allowable values
        bool reachable = false;
        for (auto value : sequence)
        {
            if (value == t)
            {
                reachable = true;
                break;
            }
        }

        if (!reachable)
        {
            cout << "-1" << endl;
            continue;
        }

        // Calculate the minimum number of changes needed
        int changes = 0;
        long long current = 0;
        while (current != t)
        {
            current = (a * current + b) % q;
            changes++;
        }

        // Count the number of distinct ways modulo (10^9 + 9)
        long long distinctWays = 0;
        current = 0;
        while (current != t)
        {
            current = (a * current + b) % q;
            distinctWays++;
        }

        cout << changes << " " << distinctWays % mod << endl;
    }
    return 0;
}
