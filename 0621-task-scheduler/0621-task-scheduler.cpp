class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Count the frequency of each task
        unordered_map<char, int> taskFreq;
        for (char task : tasks) {
            taskFreq[task]++;
        }

        // Sort tasks by frequency
        vector<int> frequencies;
        for (auto& pair : taskFreq) {
            frequencies.push_back(pair.second);
        }
        sort(frequencies.begin(), frequencies.end(), greater<int>());

        // Find the maximum frequency
        int maxFreq = frequencies[0];

        // Count the number of tasks that have the same maximum frequency
        int numMaxFreqTasks = 1;
        for (int i = 1; i < frequencies.size(); ++i) {
            if (frequencies[i] == maxFreq) {
                numMaxFreqTasks++;
            } else {
                break;
            }
        }

        // Calculate the minimum intervals required
        int minIntervals = (maxFreq - 1) * (n + 1) + numMaxFreqTasks;

        // Ensure that this value is at least the size of the tasks vector
        return max(minIntervals, (int)tasks.size());
    }
};