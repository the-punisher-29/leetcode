class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
        // Initialize two arrays to store prefix and suffix products
        vector<int> prefixProduct(n, 1);
        vector<int> suffixProduct(n, 1);
        // Calculate prefix products
        for (int i = 1; i < n; ++i) {
            prefixProduct[i] = prefixProduct[i - 1] * nums[i - 1];
        }
        // Calculate suffix products
        for (int i = n - 2; i >= 0; --i) {
            suffixProduct[i] = suffixProduct[i + 1] * nums[i + 1];
        }
        // Multiply prefix and suffix products to get the result
        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = prefixProduct[i] * suffixProduct[i];
        }
        return result;
    }
};