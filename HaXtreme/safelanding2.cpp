#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int> > &pmap, int i, int j)
{
    if (i < 0 || i >= pmap.size() || j < 0 || j >= pmap[0].size() || pmap[i][j] != 1)
    {
        return;
    }

    pmap[i][j] = -1;

    dfs(pmap, i + 1, j);
    dfs(pmap, i - 1, j);
    dfs(pmap, i, j + 1);
    dfs(pmap, i, j - 1);
}

int cl(vector<vector<int> > &pmap)
{
    int count = 0;
    for (int i = 0; i < pmap.size(); i++)
    {
        for (int j = 0; j < pmap[0].size(); j++)
        {
            if (pmap[i][j] == 1)
            {
                dfs(pmap, i, j);
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

    vector<vector<int> > pmap(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> pmap[i][j];
        }
    }

    int l = cl(pmap);
    cout << l << endl;

    return 0;
}