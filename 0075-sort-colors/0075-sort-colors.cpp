class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
/*The Three-Pointer Approach (Dutch National Flag Algorithm)
Pointers:
low: Points to the end of the 0's section (initially 0).
mid: Points to the current element being processed (initially 0).
high: Points to the start of the 2's section (initially nums.size() - 1).

Iteration: Iterate while mid is less than or equal to high.

Processing:
Case 0: If nums[mid] is 0:
Swap nums[low] and nums[mid].
Increment both low and mid.
Case 1: If nums[mid] is 1:
Increment mid.
Case 2: If nums[mid] is 2:
Swap nums[mid] and nums[high].
Decrement high.

Why This Works
The low and high pointers create boundaries for the 0's and 2's sections.
The mid pointer explores the array.
When we find a 0, we swap it with the element at the low boundary to extend the 0's section.
When we find a 2, we swap it with the element at the high boundary to extend the 2's section.
1's naturally fall into place in the middle as we rearrange 0's and 2's.*/