class Solution {
private:
    int ds(int num) {
        int sum = 0;
        while(num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> groups;
        for(int num : nums) {
            int sum = ds(num);
            groups[sum].push_back(num);
            // Keeping only two largest numbers
            if(groups[sum].size() > 2) {
                sort(groups[sum].begin(), groups[sum].end());
                groups[sum].erase(groups[sum].begin());
            }
        }
        int maxSum = -1;
        for(const auto& pair : groups) {
            const vector<int>& group = pair.second;
            if(group.size() == 2) {
                maxSum = max(maxSum, group[0] + group[1]);
            }
        }
        return maxSum;
    }
};