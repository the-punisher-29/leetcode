class FindSumPairs {
private:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> freq1;  // Frequency of nums1 elements
    unordered_map<int, int> freq2;  // Frequency of nums2 elements
    
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        
        // Build frequency maps
        for (int num : nums1) {
            freq1[num]++;
        }
        
        for (int num : nums2) {
            freq2[num]++;
        }
    }
    
    void add(int index, int val) {
        // Remove old value from frequency map
        int oldVal = nums2[index];
        freq2[oldVal]--;
        if (freq2[oldVal] == 0) {
            freq2.erase(oldVal);
        }
        
        // Update nums2 and add new value to frequency map
        nums2[index] += val;
        freq2[nums2[index]]++;
    }
    
    int count(int tot) {
        int result = 0;
        
        // For each unique value in nums1, find how many times (tot - value) appears in nums2
        for (auto& pair : freq1) {
            int val1 = pair.first;
            int count1 = pair.second;
            int needed = tot - val1;
            
            if (freq2.find(needed) != freq2.end()) {
                result += count1 * freq2[needed];
            }
        }
        
        return result;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */