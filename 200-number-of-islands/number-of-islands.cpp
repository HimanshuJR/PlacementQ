class Solution {
public:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // after visiting put it as 1 
        vis[row][col] = 1;
        // firstly make a queue
        queue<pair<int, int>> q;
        q.push({row, col});
        // Direction vectors for moving up, down, left, and right
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        // if the queue is empty or not condition and actions 
        while (!q.empty()) {
            int curRow = q.front().first;
            int curCol = q.front().second;
            q.pop();

            // to traverse through the neighbour 
            for (int i = 0; i < 4; i++) {
                int nrow = curRow + delRow[i];
                int ncol = curCol + delCol[i];

                // if condition for other cases 
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid[row][col] == '1' && !vis[row][col]) {
                    count++;
                    bfs(row, col, vis, grid);
                }
            }
        }

        return count;
    }
};
