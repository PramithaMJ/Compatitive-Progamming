#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

struct Cell
{
    int row, col, elevation;
    Cell(int r, int c, int e) : row(r), col(c), elevation(e) {}
    bool operator<(const Cell &other) const
    {
        return elevation > other.elevation;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int> > elevations(n, vector<int>(m));
    vector<vector<double> > maxFlow(n, vector<double>(m, -1.0));
    priority_queue<Cell> pq;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> elevations[i][j];
            pq.push(Cell(i, j, elevations[i][j]));
        }
    }

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    double totalFlow = 0.0;

    while (!pq.empty())
    {
        Cell current = pq.top();
        pq.pop();
        int row = current.row;
        int col = current.col;
        int elevation = current.elevation;
        double remainingFlow = 1.0;

        for (int i = 0; i < 4; i++)
        {
            int newRow = row + dr[i];
            int newCol = col + dc[i];

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m)
            {
                int newElevation = elevations[newRow][newCol];

                if (newElevation < elevation)
                {
                    if (maxFlow[newRow][newCol] == -1.0)
                    {
                        pq.push(Cell(newRow, newCol, newElevation));
                        maxFlow[newRow][newCol] = 0.0;
                    }

                    double flowToNeighbor = maxFlow[row][col] / (double)(elevation - newElevation);

                    maxFlow[newRow][newCol] += flowToNeighbor;
                    remainingFlow -= flowToNeighbor;
                }
            }
        }

        totalFlow += remainingFlow;
    }

    cout << fixed << setprecision(6) << totalFlow << endl;

    return 0;
}
