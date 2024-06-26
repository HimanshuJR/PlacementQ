class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int length1 = nums1.size();
        int end_ind = length1-1;

        while( n>0 && m> 0){
            if(nums2[n-1] >= nums1[m-1]){
                nums1[end_ind] = nums2[n-1];
                n--;
            }
            else{
                nums1[end_ind] = nums1[m-1];
                m--;
            }
            end_ind--;
        }
        while( n>0){
            nums1[end_ind] = nums2[n-1];
            n--;
            end_ind --;
        }

    }
};