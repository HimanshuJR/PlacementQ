class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // implement the queue as a pair
        queue<pair<pair<int, int>, int>> q;
       int fresh_oranges = 0;

       for( int i = 0;i <n;i++){
        for( int j = 0; j<m ; j++){
            if(grid[i][j] == 2){
             q.push({{i, j}, 0});
            }
            else if(grid[i][j] == 1){
                fresh_oranges++;
            }
         }
       }
       
       // direction for up right down left
       vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int maxtime = 0;

        // bfs to rot the oranges

        while(!q.empty()){
            auto current = q.front();
            q.pop();

            int row = current.first.first;
            int col = current.first.second;
            int time = current.second;

            // updation of maximum time 
            maxtime = max(maxtime,time);

            for( auto dir: directions){
                int newRow = row + dir.first;
                int newCol = col + dir.second;

                if( newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 1){
                    grid[newRow][newCol] = 2;
                     q.push({{newRow, newCol}, time + 1});
                    fresh_oranges--;

                }
            }

        }
        if( fresh_oranges > 0){
            return -1;
        }
        return maxtime;
     
    }
};