class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        unordered_map<string,int> count;
        // combine two string with a space 
        stringstream ss(s1 + " " + s2);
        string word;
        // mark frequency of the words 
        while (ss >> word){
            count[word]++;
        }

        for(auto& it : count){
            if(it.second == 1){
                ans.push_back(it.first);
            }
        }
        return ans;


    }
};