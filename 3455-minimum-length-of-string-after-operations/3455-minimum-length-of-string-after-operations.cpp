// class Solution {
// public:
//     int minimumLength(string s) {
//         int l=0;
//         int r=s.length()-1;
//         while (l<r&&s[l]==s[r]){
//             char current=s[l];
//             while (l<=r&&s[l]==current){
//                 l++;
//             }
//             while(l<=r&&s[r]==current) {
//                 r--;
//             }
//         }
//         return r-l+1;
//     }
// };
// class Solution {
// public:
//     int minimumLength(string s) {
//         bool canReduce = true;
//         while (canReduce) {
//             canReduce = false;
//             int n = s.length();
            
//             // Try each index as potential i
//             for (int i = 0; i < n; i++) {
//                 // Find closest match to left
//                 int leftMatch = -1;
//                 for (int j = i - 1; j >= 0; j--) {
//                     if (s[j] == s[i]) {
//                         leftMatch = j;
//                         break;
//                     }
//                 }
                
//                 // Find closest match to right
//                 int rightMatch = -1;
//                 for (int j = i + 1; j < n; j++) {
//                     if (s[j] == s[i]) {
//                         rightMatch = j;
//                         break;
//                     }
//                 }
                
//                 // If we found matches on both sides
//                 if (leftMatch != -1 && rightMatch != -1) {
//                     // Remove the characters (replace with special character)
//                     s[leftMatch] = '#';
//                     s[rightMatch] = '#';
//                     canReduce = true;
//                     break;  // Process one operation at a time
//                 }
//             }
            
//             // Remove the marked characters
//             if (canReduce) {
//                 string temp;
//                 for (char c : s) {
//                     if (c != '#') {
//                         temp += c;
//                     }
//                 }
//                 s = temp;
//             }
//         }
//         return s.length();
//     }
// };--tle
class Solution {
 public:
  int minimumLength(string s) {
    int ans = 0;
    vector<int> count(26);
    for (const char c : s)
      ++count[c - 'a'];
    for (int i = 0; i < 26; ++i)
      if (count[i] > 0)
        ans += count[i] % 2 == 0 ? 2 : 1;
    return ans;
  }
};