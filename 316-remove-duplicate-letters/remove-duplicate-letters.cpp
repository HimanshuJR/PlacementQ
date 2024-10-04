class Solution {
public:
    string removeDuplicateLetters(string s) {
     // Frequency of each character in the string
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

        // To keep track of which characters are in the result
        unordered_set<char> seen;
        stack<char> st; // Stack to maintain the resulting characters

        for (char ch : s) {
            freq[ch]--; // Decrease frequency as we process this character

            if (seen.find(ch) != seen.end()) {
                continue; // Skip if character is already in the result
            }

            // Maintain lexicographical order
            while (!st.empty() && st.top() > ch && freq[st.top()] > 0) {
                seen.erase(st.top()); // Remove from seen set
                st.pop(); // Remove from stack
            }

            // Add current character to stack and seen set
            st.push(ch);
            seen.insert(ch);
        }

        // Build the result from the stack
        string result = "";
        while (!st.empty()) {
            result = st.top() + result; // Construct the result in correct order
            st.pop();
        }
        
        return result;
    }
};