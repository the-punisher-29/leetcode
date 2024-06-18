class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> jobs;
        int n=difficulty.size();
        for(int i=0;i<n;++i){
            jobs.emplace_back(difficulty[i],profit[i]);
        }
        sort(jobs.begin(),jobs.end());
        sort(worker.begin(),worker.end());
        int mp=0,bp=0,i=0;
        for(int ability:worker){
            while(i<n && jobs[i].first<=ability){
                bp=max(bp,jobs[i].second);
                i++;
            }
            mp+=bp;
        }
        return mp;
    }
};