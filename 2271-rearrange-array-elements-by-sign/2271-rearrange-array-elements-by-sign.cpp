class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive;
        vector<int> negative;
        vector<int> result;

        for (int num : nums) {
            if (num > 0)
                positive.push_back(num);
            else
                negative.push_back(num);
        }

        int i = 0, j = 0;
        while (i < positive.size() && j < negative.size()) {
            result.push_back(positive[i++]);
            result.push_back(negative[j++]);
        }
        return result;
    }
};