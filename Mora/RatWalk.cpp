#include <iostream>
#include <vector>

using namespace std;

struct Sensor {
    int x, y;
};

void dfs(int y, int x, vector<int>& grid, int W) {
    if (y < 0 || y >= W || x < 0 || x >= W || grid[y * W + x] == 1) {
        return;
    }

    grid[y * W + x] = 1;

    dfs(y - 1, x, grid, W);
    dfs(y, x - 1, grid, W);
    dfs(y, x + 1, grid, W);
}

string canRatPass(int W, int H, int N, int R, vector<Sensor>& sensors) {
    vector<int> grid(W * W, 0);

    for (int i = 0; i < N; i++) {
        int x = sensors[i].x;
        int y = sensors[i].y;

        for (int dx = -R; dx <= R; dx++) {
            for (int dy = -R; dy <= R; dy++) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < W && ny >= 0 && ny < W) {
                    grid[ny * W + nx] = 1;
                }
            }
        }
    }

    for (int x = 0; x < W; x++) {
        if (grid[x] == 0) {
            dfs(W - 1, x, grid, W); 
            for(int y = 0; y < W; y++) {
                if(grid[y * W + x] == 0) {
                    return "CAN";
                }
            }
        }
    }

    return "CAN'T";
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int W, H, N, R;
        cin >> W >> H >> N >> R;

        vector<Sensor> sensors(N);

        for (int i = 0; i < N; i++) {
            cin >> sensors[i].x;
        }

        for (int i = 0; i < N; i++) {
            cin >> sensors[i].y;
        }

        string result = canRatPass(W, H, N, R, sensors);
        cout << result << endl;
    }

    return 0;
}