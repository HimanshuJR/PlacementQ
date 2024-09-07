class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if( n== 0) return 0;
        int l = 0; int r= n-1; int total = 0;
        int lmax= INT_MIN; int rmax = INT_MIN;
        while( l<r){
            if(height[l] <= height[r]){
            if( height[l] < lmax)  total += lmax-height[l];
               else lmax = height[l];
               l++;
            }else{ 
            if( height[r] < rmax) total += rmax-height[r];
                else   rmax = height[r];  
            r--;
            }
        }
        return total;
    }
};