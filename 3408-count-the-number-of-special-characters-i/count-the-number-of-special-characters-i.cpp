class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,bool> lowerMap, upperMap;
        for(auto ch : word){
            if(islower(ch)){
                lowerMap[ch] = true;
            }else if(isupper(ch)){
                upperMap[tolower(ch)] = true;
            }
        }
        int specialCount = 0;
        for(auto& pair : lowerMap){
            if(upperMap[pair.first]){
                specialCount ++;
            }
        }
        return specialCount;
    }
};