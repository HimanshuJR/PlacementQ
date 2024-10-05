class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int start = 0;
        int end = n-1;
        int maxArea = 0;

        while(start < end){
            int width = end-start;
            int heights = min(height[start],height[end]);
            int Area = width*heights;
            maxArea = max(maxArea,Area);

            if(height[start] < height[end]){
                start++;
            }else{
                end--;
            }
        }
        return maxArea;
    }
};