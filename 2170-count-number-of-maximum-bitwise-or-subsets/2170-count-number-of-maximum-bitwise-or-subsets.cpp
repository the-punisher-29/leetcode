class Solution {
public:
    int maxOrValue;         
    int subsetCount;        
    vector<int> numbers;    
    int countMaxOrSubsets(vector<int>& nums) {
        numbers = nums;     
        maxOrValue = 0;    
        subsetCount = 0;    
        for (int x : nums) {
            maxOrValue |= x;
        }
        dfs(0, 0);
        return subsetCount;
    }
    void dfs(int index, int currentOrValue) {
        if (index == numbers.size()) {
            if (currentOrValue == maxOrValue) {
                subsetCount++;
            }
            return;
        }
        // Case 1: Excluding the current number from the subset and continue to the next element
        dfs(index + 1, currentOrValue);
        // Case 2: Including the current number in the subset (OR the current value with this number) and continue
        dfs(index + 1, currentOrValue | numbers[index]);
    }
};