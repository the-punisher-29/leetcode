class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> fmp;
        for (int num : nums) {
            fmp[num]++;
        }
        //bkt sort
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& [num, freq] : fmp) {
            buckets[freq].push_back(num);
        }
        vector<int> result;
        for (int i = buckets.size() - 1; i >= 0 && result.size() < k; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }
        return result;
    }
};