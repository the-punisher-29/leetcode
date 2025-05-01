class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        // Sort tasks in ascending order (easiest first)
        sort(tasks.begin(), tasks.end());
        // Sort workers in ascending order (weakest first)
        sort(workers.begin(), workers.end());
        
        // Binary search to find the maximum number of tasks we can complete
        int left = 0, right = min(tasks.size(), workers.size());
        
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (canComplete(tasks, workers, pills, strength, mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        
        return left;
    }
    
private:
    bool canComplete(const vector<int>& tasks, const vector<int>& workers, int pills, int strength, int k) {
        // Take the k easiest tasks
        vector<int> currTasks(tasks.begin(), tasks.begin() + k);
        
        // Take the k strongest workers
        vector<int> currWorkers;
        for (int i = workers.size() - k; i < workers.size(); i++) {
            currWorkers.push_back(workers[i]);
        }
        
        // Pills available to use
        int remainingPills = pills;
        
        // Process tasks from hardest to easiest
        for (int i = k - 1; i >= 0; i--) {
            int task = currTasks[i];
            
            // If the strongest worker can do the task without a pill
            if (currWorkers[i] >= task) {
                continue;
            }
            
            // If the strongest worker can't do the task even with a pill, or no pills left
            if (currWorkers[i] + strength < task || remainingPills == 0) {
                return false;
            }
            
            // Find a worker who can do the task with a pill using binary search
            // We want the weakest eligible worker to use the pill
            int left = 0, right = i;
            while (left < right) {
                int mid = (left + right) / 2;
                if (currWorkers[mid] + strength >= task) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            
            // Use a pill on the worker found
            currWorkers.erase(currWorkers.begin() + left);  // Remove this worker as they've been assigned
            currWorkers.push_back(INT_MAX);  // Add a dummy worker to maintain array size
            remainingPills--;
        }
        
        return true;
    }
};