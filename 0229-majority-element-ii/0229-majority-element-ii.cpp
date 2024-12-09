class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // unordered_map<int, int> count;
        // vector<int> result;
        // int threshold = nums.size() / 3;
        // for (int num : nums) {
        //     count[num]++;
        // }
        // for (auto& [num, freq] : count) {
        //     if (freq > threshold) {
        //         result.push_back(num);
        //     }
        // }
        // return result;
        
        //---------------------------Learning-O(1)Space----------------------------------------
        // Boyer-Moore Voting Algorithm: O(n) time, O(1) space
        // At most 2 elements can appear more than ⌊n/3⌋ times
        int candidate1 = 0, candidate2 = 0;
        int count1 = 0, count2 = 0;
        // First pass: find potential candidates
        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            }
            else if (num == candidate2) {
                count2++;
            }
            else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            }
            else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }
        // Second pass: verify candidates
        count1 = count2 = 0;
        for (int num : nums) {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
        }
        vector<int> result;
        int threshold = nums.size() / 3;
        if (count1 > threshold) result.push_back(candidate1);
        if (count2 > threshold && candidate2 != candidate1) result.push_back(candidate2);
        return result;
    }
};