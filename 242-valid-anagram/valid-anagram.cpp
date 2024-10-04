class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        unordered_map<char,int> count;
        for(auto it : s){
            count[it]++;
        }
        for(auto it : t){
            count[it]--;
            if(count[it] <0){
                return false;
            }
        }
        return true;


    }
};