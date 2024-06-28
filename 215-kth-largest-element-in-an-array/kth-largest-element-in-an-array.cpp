class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int> q;

        for(int x : nums){
            q.push(x);
        }
        for( int i = 0;i < k-1;i++){
            q.pop();
        }
        return q.top();
    }
};