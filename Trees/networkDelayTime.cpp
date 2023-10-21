#include <vector>
#include <map>
#include <queue>
#include <iostream>
#include <limits>

using namespace std;

class Solution {
public:
    int networkDelayTime( vector<vector<int>> & times, int n, int k) {
    map<int, map<int, int>> adj;
        for (const vector<int>& time : times) {
            adj[time[0]][time[1]] = time[2];
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
        queue.push({0, k});
        vector<bool> vis(n + 1, false);
        int res = 0;

        while (!queue.empty()) {
            pair<int, int> rv = queue.top();
            queue.pop();
            int currNode = rv.second;
            int time = rv.first;
            if (vis[currNode])
                continue;
            vis[currNode] = true;
            res = time;
            n--;
            if (n == 0)
                break;
            if (adj.find(currNode) != adj.end()) {
                for (const auto& entry : adj[currNode]) {
                    int child = entry.first;
                    int childTime = entry.second;
                    queue.push({time + childTime, child});
                }
            }
        }

        return n == 0 ? res : -1;
    }
};
