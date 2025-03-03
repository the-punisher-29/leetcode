class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> res;
        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();
        //twoptr approach
        while (i < n || j < m) {
            // Case 1: Only nums1 has elements left
            if (j == m || (i < n && nums1[i][0] < nums2[j][0])) {
                res.push_back(nums1[i]);
                i++;
            }
            // Case 2: Only nums2 has elements left
            else if (i == n || (j < m && nums2[j][0] < nums1[i][0])) {
                res.push_back(nums2[j]);
                j++;
            }
            // Case 3: Both arrays have the same id
            else {
                int id = nums1[i][0]; // Same as nums2[j][0]
                int sumVal = nums1[i][1] + nums2[j][1];
                res.push_back({id, sumVal});
                i++;
                j++;
            }
        }
        return res;
    }
};