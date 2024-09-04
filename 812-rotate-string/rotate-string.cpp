#include <string>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }
        string doubled = s + s;  // Concatenate the string with itself
        return doubled.find(goal) != string::npos;  // Check if goal is a substring
    }
};
