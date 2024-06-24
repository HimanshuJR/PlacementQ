class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> outdegree(n,0);
       
       
        vector<vector<int>> RevGraph(n);
        // make a reverse graph and calculate the outdegree

        for( int u = 0; u < n;u++){
            for(int it : graph[u]){
                RevGraph[it].push_back(u);
                outdegree[u]++;

            }
        }
        queue<int> q;
        vector<int> SafeNodes;
        // if the out degree is 0 then push it into the queue 
        for(int i = 0;i < n;i++){
            if(outdegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            SafeNodes.push_back(u);

            for (int v : RevGraph[u]) {
                --outdegree[v];
                if (outdegree[v] == 0) {
                    q.push(v);
                }
            }
        }
         
 sort(SafeNodes.begin(), SafeNodes.end());
        return SafeNodes;


    }
};