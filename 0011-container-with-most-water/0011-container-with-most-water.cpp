//brute-force--cal area between each two pts...two loops--[O(n^2)]
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int n = height.size();
//         int maxArea = 0;
        
//         for (int i = 0; i < n - 1; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 int width = j - i;
//                 int h = min(height[i], height[j]);
//                 int area = width * h;
                
//                 maxArea = max(maxArea, area);
//             }
//         }
        
//         return maxArea;
//     }
// };
//optimal---two ptr approach--[tc-O(n) nd sc-O(1) as no extra ds created]
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int ma=0;

        while(l<r){
            int w=r-l;
            int h=min(height[l],height[r]);
            int a=w*h;
            ma=max(ma,a);
            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return ma;
    }
};