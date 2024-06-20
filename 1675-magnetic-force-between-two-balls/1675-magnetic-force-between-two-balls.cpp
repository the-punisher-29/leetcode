class Solution {
public:
    bool canPlace(vector<int>& position, int m, int dist) {
        int count = 1;
        int last = position[0];
        
        for (int i = 1; i < position.size(); i++) {
            if (position[i] - last >= dist) {
                count++;
                last = position[i];
                if (count == m) return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        
        int left = 1;
        int right = (position.back() - position.front()) / (m - 1);
        int result = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canPlace(position, m, mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
};