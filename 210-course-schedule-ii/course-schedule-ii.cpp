#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build adjacency list and indegree array
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        queue<int> q;
        vector<int> order;

        // Enqueue all nodes with 0 indegree
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Process nodes
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order.push_back(node);

            // Reduce the indegree of neighboring nodes by 1
            for (auto neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If the order size is not equal to the number of courses, there is a cycle
        if (order.size() != numCourses) {
            return {};
        }

        return order;
    }
};
