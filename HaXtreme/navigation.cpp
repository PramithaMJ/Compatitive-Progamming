#include <iostream>
#include <vector>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isValid(int x, int y, vector<vector<int>> &space)
{
    int rows = space.size();
    int cols = space[0].size();
    return x >= 0 && x < rows && y >= 0 && y < cols && space[x][y] != 1;
}

vector<pair<int, int>> dfs(vector<vector<int>> &space, pair<int, int> start, pair<int, int> wormhole)
{
    if (start == wormhole)
    {
        vector<pair<int, int>> path;
        path.push_back(wormhole);
        return path;
    }

    for (int i = 0; i < 4; ++i)
    {
        int new_x = start.first + dx[i];
        int new_y = start.second + dy[i];
        if (isValid(new_x, new_y, space))
        {
            vector<pair<int, int>> path = dfs(space, {new_x, new_y}, wormhole);
            if (!path.empty())
            {
                path.insert(path.begin(), start);
                return path;
            }
        }
    }

    return vector<pair<int, int>>(); // Empty path
}

int main()
{
    int start_x, start_y;
    cin >> start_x >> start_y;

    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> space(rows, vector<int>(cols));

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cin >> space[i][j];
        }
    }

    pair<int, int> wormhole;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (space[i][j] == 2)
            {
                wormhole = make_pair(i, j);
                break;
            }
        }
    }

    vector<pair<int, int>> bestPath = dfs(space, make_pair(start_x, start_y), wormhole);

    for (const auto &cell : bestPath)
    {
        cout << cell.first << " " << cell.second << endl;
    }

    return 0;
}