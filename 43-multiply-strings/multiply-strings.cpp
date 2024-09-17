class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size(); 
        int m = num2.size();
        
        // Special case: if either number is "0", return "0"
        if (num1 == "0" || num2 == "0") return "0";
        
        vector<int> result(n + m, 0);  // Vector to store the intermediate results

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');  // Multiplying individual digits
                int sum = mul + result[i + j + 1];  // Adding to the current position

                result[i + j + 1] = sum % 10;  // Storing the current digit
                result[i + j] += sum / 10;  // Adding the carry to the next position
            }
        }

        string final_ans = "";
        for (auto num : result) {
            if (!(final_ans.empty() && num == 0)) {  // Skip leading zeros
                final_ans.push_back(num + '0');
            }
        }

        // Return "0" if the final_ans is empty (all elements were zeros)
        return final_ans.empty() ? "0" : final_ans;
    }
};
