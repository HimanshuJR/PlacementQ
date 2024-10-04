class Solution {
public:
    bool isPalindrome(string s) {
       
        string filtered;
        for(auto ch : s){
           if(isalnum(ch)){
                filtered += tolower(ch);
            }
        }
         int n = filtered.size();
        int start = 0;
        int end = n-1;
        while (start < end){
            if(filtered[start] != filtered[end]){
                return false;
            }
            start++;
            end--;

        }
        return true;
    }
};