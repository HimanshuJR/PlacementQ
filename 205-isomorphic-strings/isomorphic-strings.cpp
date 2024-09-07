class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char,int> sMap;
         unordered_map<char,int> tMap;

         for(int i =0 ; i<s.size();i++){
            int schar = s[i];
            int tchar = t[i];
            if(sMap.find(schar) != sMap.end()){
                if(sMap[schar] != tchar) return false;
            }
                else {
                    sMap[schar] = tchar;
                }
            if(tMap.find(tchar) != tMap.end()){
                if(tMap[tchar] != schar) return false;
            }
                else {
                    tMap[tchar] = schar;
                }
         }
         return true;

    }
};