typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define mppp make_pair
#define f first
#define s second
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define repe(i, a, b) for(int i = a; i <= (b); ++i)
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int c1=0;
        //counting 1s!
        for (int num : nums) {
            if (num == 1)c1++;
        }
        //trivial cases handling
        if (c1==n) return 0;
        //if (c1==0) return -1;
        //one_insight: We can only change the parity of elements at specific positions relative to where we start flipping
        //int min_ops=INT_MAX;
        // Trying each possible starting position
        // repe(i,0,n-3){
        //     vector<int> temp = nums;
        //     int ops=0;
        //     repe(j,i,n-3){
        //         if (temp[j]==0) {
        //             temp[j]=1;
        //             temp[j+1] ^= 1;
        //             temp[j+2] ^= 1;
        //             ops++;
        //         }
        //     }
        //     bool ao=1;
        //     rep(j,0,n){
        //         if (temp[j] == 0) {
        //             ao=0;
        //             break;
        //         }
        //     }
        //     if (ao) {
        //         min_ops= min(min_ops, ops);
        //     }
        // }
        // return min_ops== INT_MAX ? -1 : min_ops;
        int count=0;
        rep(i,2,n){
            // only looking forward to the last element
            if (nums[i - 2] == 0) {
                count++;
                // flipping i-2 and i-1 and i
                nums[i - 2] ^= 1;
                nums[i - 1] ^= 1;
                nums[i] ^= 1;
            }
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum==n) return count;
        return -1;
    }
};