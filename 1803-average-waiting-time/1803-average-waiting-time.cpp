class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long totalWaitingTime = 0;
        int currentTime = 0;
        
        for (const auto& customer : customers) {
            int arrivalTime = customer[0];
            int preparationTime = customer[1];
            //curr time
            currentTime = max(currentTime, arrivalTime);
            //req finish time for ith cus
            int finishTime = currentTime + preparationTime;
            //cons waiting time
            int waitingTime = finishTime - arrivalTime;
            //net wait time addition
            totalWaitingTime += waitingTime;
            //curr time updation for next cus
            currentTime = finishTime;
        }
        //avg wait time
        return static_cast<double>(totalWaitingTime) / customers.size();
    }
};