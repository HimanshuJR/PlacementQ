// we can also use stack as it is last in first out 
class Solution {
public:
    void reverseString(vector<char>& s){
      
       stack<int> stack;

        // size of the string 
        int n = s.size();
        // traverse through string
         for( int i = 0; i <n ;i++){
           stack.push(s[i]);

         }

         for( int i = 0; i <n ;i++){
          s[i] =  stack.top();
          stack.pop();

         }
         
    }
};