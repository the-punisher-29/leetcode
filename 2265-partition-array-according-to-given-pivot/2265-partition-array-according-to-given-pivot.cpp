class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> res(n);
        vector<int> l,e,g;
        //batwara
        for (int num : nums) {
            if (num < pivot) {
                l.push_back(num);
            } else if (num == pivot) {
                e.push_back(num);
            } else {
                g.push_back(num);
            }
        }
        int index = 0;
        // Adding elements less than pivot
        for (int num:l) {
            res[index++] = num;
        }
        // Adding elements equal to pivot
        for (int num : e) {
            res[index++] = num;
        }
        // Adding elements greater than pivot
        for (int num : g) {
            res[index++] = num;
        }
        return res;
    }
};