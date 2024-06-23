class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        int tortoise = nums[0];
        int hare = nums[0];
        
        // Phase 1: Find the intersection point of the two pointers
        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);
        
        // Phase 2: Find the entrance to the cycle
        tortoise = nums[0];
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        
        // The entrance to the cycle is the duplicate number
        return hare;
    }
};