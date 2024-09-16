class Solution {
public:
int is_pal(string s){
    int i = 0 ; int j = s.length() - 1 ;
    while(i < j){
        if(s[i] != s[j]){
            return false ;
        }
        i++;j-- ;
    }
    return true ;
}
    bool validPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int end = n-1;

        while(start <= end){
            if(s[start] == s[end]){
                start++;
                end--;
            }else{
 return is_pal(s.substr(0 , start) + s.substr(start+1)) || is_pal(s.substr(0 , end) + s.substr(end+1)) ;
            }
        }
        return true;
    }
};