//greddy approach-starting with largest rom num and then work my way down
class Solution {
public:
    string intToRoman(int num) {
        const vector<pair<int, string>> romanSymbols = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };
        string result = "";
        for (const auto &[value, symbol] : romanSymbols) {
            // While the number is greater than or equal to the current value
            while (num >= value) {
                // Append the corresponding symbol to the result
                result += symbol;
                // Subtract the value from the number
                num -= value;
            }
        }
        return result;
    }
};