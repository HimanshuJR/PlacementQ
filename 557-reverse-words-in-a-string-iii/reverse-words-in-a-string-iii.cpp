class Solution {
public:
string reverseword(string s){
    string rev;
    stack<char> s1;
    for(auto it : s){
        s1.push(it);
    }
   while(!s1.empty()){
        rev += s1.top();
        s1.pop();
    }
    return rev;
}
    string reverseWords(string s) {
        string result;  string word;
        for( char ch : s){
            if( ch == ' '){
                result += reverseword(word) + ' ';
                word = "";
            }else{
                word += ch;

            }
        }
        result += reverseword(word);
        return result;
    }
};