#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int> > &planet_map, int i, int j)
{
    if (i < 0 || i >= planet_map.size() || j < 0 || j >= planet_map[0].size() || planet_map[i][j] != 1)
    {
        return;
    }

    planet_map[i][j] = -1;

    dfs(planet_map, i + 1, j);
    dfs(planet_map, i - 1, j);
    dfs(planet_map, i, j + 1);
    dfs(planet_map, i, j - 1);
}

int count_landmasses(vector<vector<int> > &planet_map)
{
    int count = 0;
    for (int i = 0; i < planet_map.size(); i++)
    {
        for (int j = 0; j < planet_map[0].size(); j++)
        {
            if (planet_map[i][j] == 1)
            {
                dfs(planet_map, i, j);
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int> > planet_map(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> planet_map[i][j];
        }
    }

    int num_landmasses = count_landmasses(planet_map);
    cout << num_landmasses << endl;

    return 0;
}