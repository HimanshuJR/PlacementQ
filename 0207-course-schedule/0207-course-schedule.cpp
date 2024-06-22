class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses, 0);

        // Build the adjacency list and indegree array
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        // Queue to maintain courses with no prerequisites
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0; // To count the number of courses we can complete
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            // Reduce the indegree of neighboring nodes by 1
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // If we are able to count all courses, it means we can finish all of them
        return count == numCourses;
    }
};
