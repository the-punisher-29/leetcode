// class Solution {
// public:
//     long long pickGifts(vector<int>& gifts, int k) {
//         for(int i=0;i<k;++i){
//             int j=*max_element(gifts.begin(),gifts.end());
//             gifts[j]=floor(pow(gifts[j],0.5));
//         }
//         int res;
//         for(int i=0;i<gifts.size();++i){
//             res+=gifts[i];
//         }
//         return res;
        
//     }
// };
// class Solution {
// public:
//     long long pickGifts(vector<int>& gifts, int k) {
//         // Iterate k times
//         for(int i = 0; i < k; ++i) {
//             // Find index of max element
//             int maxIndex = max_element(gifts.begin(), gifts.end()) - gifts.begin();
            
//             // Replace with floor of square root
//             gifts[maxIndex] = floor(sqrt(gifts[maxIndex]));
//         }
        
//         // Sum remaining gifts
//         long long res = 0;
//         for(int gift : gifts) {
//             res += gift;
//         }
        
//         return res;
//     }
// };

//pq sol

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(), gifts.end());
        
        for (int i = 0; i < k; i++) {
            if (pq.empty()) break;
            
            int maxPile = pq.top();
            pq.pop();
            pq.push(floor(sqrt(maxPile)));
        }
        
        long long totalGifts = 0;
        while (!pq.empty()) {
            totalGifts += pq.top();
            pq.pop();
        }
        
        return totalGifts;
    }
};