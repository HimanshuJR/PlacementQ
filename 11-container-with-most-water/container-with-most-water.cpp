class Solution {
public:
    int maxArea(vector<int>& height) {
        int n  = height.size();
        int start = 0;
        int end = n-1;
        int MaxArea = 0;

        while(start < end){
            int width = end-start;
            int h = min(height[start], height[end]);
            int Area = width * h;

            MaxArea = max(MaxArea,Area);

            if(height[start] < height[end]){
                start++;
            }else{
                end--;
            }


        }
        return MaxArea;
    }
};