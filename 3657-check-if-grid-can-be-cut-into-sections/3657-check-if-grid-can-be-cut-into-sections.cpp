// class Solution {
// private:
//     static const int MAXN = 100000; 
//     static const long long MOD = 1000000007;
// public:
//     bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
//         if (canPartition(rectangles, n,false)) {
//             return true;
//         }
//         if (canPartition(rectangles, n,true)) {
//             return true;
//         }
//         return false;
//     }
    
// private:
//     bool canPartition(const vector<vector<int>>& rects, int n, bool vertical) {
//         vector<int> diff(n+1, 0); // crossCount array
//         vector<int> starts, ends; 
//         starts.reserve(rects.size());
//         ends.reserve(rects.size());
//         for (auto &r : rects) {
//             int start = vertical ? r[0] : r[1];  // x1 or y1
//             int end   = vertical ? r[2] : r[3];  // x2 or y2
//             starts.push_back(start);
//             ends.push_back(end);
//             if (end > start + 1) {
//                 int low = start + 1;
//                 int high = end; // we will do diff[high]--
//                 if (low < n) {
//                     diff[low]++;
//                 }
//                 if (high <= n-1) {
//                     diff[high]--;
//                 }
//             }
//         }
//         for(int i = 1; i < n; i++){
//             diff[i] += diff[i-1];
//         }
//         vector<int> validLines; 
//         for(int L = 1; L < n; L++){
//             if(diff[L] == 0) {
//                 validLines.push_back(L);
//             }
//         }
//         if((int)validLines.size() < 2) return false;
//         sort(ends.begin(), ends.end());
//         sort(starts.begin(), starts.end());
//         int M = (int)rects.size();
//         auto countBelow = [&](int L){
//             return (int)(upper_bound(ends.begin(), ends.end(), L) - ends.begin());
//         };
//         auto countAbove = [&](int L){
//             return (int)(starts.end() - lower_bound(starts.begin(), starts.end(), L));
//         };
//         int rSize = (int)validLines.size();
//         for(int i = 0; i < rSize - 1; i++){
//             int L1 = validLines[i];
//             int part1 = countBelow(L1);
//             if(part1 == 0) continue;
//             for(int j = i+1; j < rSize; j++){
//                 int L2 = validLines[j];
//                 if(L2 <= L1) continue;
//                 int part3 = countAbove(L2);
//                 if(part3 == 0) continue;
//                 int part2 = M - part1 - part3;
//                 if(part2 > 0) {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return checkCuts(rectangles, 0) || checkCuts(rectangles, 1);
    }

private:
    bool checkCuts(vector<vector<int>>& rectangles, int dim) {
        int gapCount = 0;
        sort(rectangles.begin(), rectangles.end(),
             [dim](const vector<int>& a, const vector<int>& b) {
                 return a[dim] < b[dim];
             });
        int furthestEnd = rectangles[0][dim + 2];
        for (size_t i = 1; i < rectangles.size(); i++) {
            vector<int>& rect = rectangles[i];

            // If current rectangle starts after the furthest end we've seen,
            // we found a gap where a cut can be made
            if (furthestEnd <= rect[dim]) {
                gapCount++;
            }

            // Update the furthest ending coordinate
            furthestEnd = max(furthestEnd, rect[dim + 2]);
        }

        // We need at least 2 gaps to create 3 sections
        return gapCount >= 2;
    }
};
