class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        //k is greater than blk size
        if (k > n) return -1;
        // Counting w blk in window of k
        int wc=0;
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') {
                wc++;
            }
        }
        int minops=wc;
        //aage badhao window ko
        for (int i = k; i < n; i++) {
            //rem contri of leaving char
            if (blocks[i - k] == 'W') {
                wc--;
            }
            //add contri of incom char
            if (blocks[i] == 'W') {
                wc++;
            }
            minops=min(minops,wc);
        }
        return minops;
    }
};