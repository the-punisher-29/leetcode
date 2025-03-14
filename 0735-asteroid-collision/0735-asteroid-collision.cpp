class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        for (int asteroid : asteroids) {
            // Flag to track if current asteroid survives
            bool destroyed = false;
            while (!result.empty() && result.back() > 0 && asteroid < 0 && !destroyed) {
                // Case: current asteroid is destroyed (smaller magnitude)
                if (abs(result.back()) > abs(asteroid)) {
                    destroyed = true;
                }
                // Case: both asteroids are destroyed (equal magnitude)
                else if (abs(result.back()) == abs(asteroid)) {
                    result.pop_back();
                    destroyed = true;
                }
                // Case: previous asteroid is destroyed (smaller magnitude)
                else {
                    result.pop_back();
                }
            }
            if (!destroyed) {
                result.push_back(asteroid);
            }
        }
        return result;
    }
};