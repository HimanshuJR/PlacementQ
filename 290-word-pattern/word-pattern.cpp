#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = s.size();
        vector<string> words;
        string word;
        
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                word += s[i];
            } else if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        if (!word.empty()) {
            words.push_back(word);
        }

        if (pattern.size() != words.size()) {
            return false;
        }

        unordered_map<char, string> patternToWord;
        unordered_map<string, char> wordToPattern;

        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];

            // Check the char in the pattern if it matches the word
            if (patternToWord.count(c)) {
                if (patternToWord[c] != w) {
                    return false;
                } // Mistake: Should not update the mapping here
            } else {
                patternToWord[c] = w;  // Correct mapping
            }

            if (wordToPattern.count(w)) {
                if (wordToPattern[w] != c) {
                    return false;
                } // Mistake: Should not update the mapping here
            } else {
                wordToPattern[w] = c;  // Correct mapping
            }
        }

        return true;
    }
};
