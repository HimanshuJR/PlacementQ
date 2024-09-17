class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> count1  , count2;

        for(auto it : words1){
            count1[it]++;
        }

        for(auto it : words2){
            count2[it]++;
        }
        int count = 0;

        for(auto& it : count1 ){
            const string& word = it.first; 
            if(it.second == 1 && count2[word] == 1){
                count++;
            }
        }
        return count;
    }
};