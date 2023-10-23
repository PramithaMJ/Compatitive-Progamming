#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_map> 
#include<string>
using namespace std;

long long squared_distance(pair<int, int> p1, pair<int, int> p2)
{
    long long dx = p1.first - p2.first;
    long long dy = p1.second - p2.second;
    return (dx * dx + dy * dy);
}

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    
    vector<pair<int, int>> spies(N);
    vector<pair<int, int>> camps(M);

    for (int i = 0; i < N; i++)
    {
        cin >> spies[i].first >> spies[i].second;
    }
    for (int i = 0; i < M; i++)
    {
        cin >> camps[i].first >> camps[i].second;
    }

    vector<long long> min_squared_distances;

    for (int i = 0; i < K; i++)
    {
        min_squared_distances.push_back(LLONG_MAX);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            long long dist = squared_distance(spies[i], camps[j]);

            for (int k = 0; k < K; k++)
            {
                if (dist < min_squared_distances[k])
                {
                    swap(dist, min_squared_distances[k]);
                }
            }
        }
    }

    long long result = 0;
    for (int i = 0; i < K; i++)
    {
        result += min_squared_distances[i];
    }
    cout << result << endl;

    return 0;
}