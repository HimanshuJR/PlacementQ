class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int start = 0;
        int end = n-1;
        int mid = (start+end)/2;
        int peak;
        
        
         while(start < end){
             mid = (start+end)/2;
       
            if(arr[mid] < arr[mid+1]){
                start = mid+1;

            }
            else{
                end = mid;
            }
           
    

         }
         return start;
        
    }
};