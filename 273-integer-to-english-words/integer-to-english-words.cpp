class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";

        string bigString[] = {"Thousand", "Million", "Billion"};
        string result = numberToWordsHelper(num % 1000); // Correct initial call
        num /= 1000;

        for (int i = 0; i < 3; ++i) {
            if (num > 0) {
                if (num % 1000 > 0) {
                    result = numberToWordsHelper(num % 1000) + bigString[i] + " " + result;
                }
                num /= 1000;
            }
        }

        if (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }

private:
    string numberToWordsHelper(int num) {
        string digitString[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        string teenString[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string tenString[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string result = "";

        if (num >= 100) {
            result += digitString[num / 100] + " Hundred "; // Correct spacing
            num %= 100;
        }
        if (num >= 20) { // Correct condition
            result += tenString[num / 10] + " ";
            num %= 10;
        } else if (num >= 10) { // Correct condition
            result += teenString[num - 10] + " ";
            return result; 
        }
        if (num > 0) {
            result += digitString[num] + " ";
        }
        return result;
    }
};
