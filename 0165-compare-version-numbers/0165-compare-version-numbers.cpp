class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1 = splitVersion(version1);
        vector<int> v2 = splitVersion(version2);
        int n = max(v1.size(), v2.size());
        for (int i = 0; i < n; i++) {
            int num1 = (i < v1.size()) ? v1[i] : 0;
            int num2 = (i < v2.size()) ? v2[i] : 0;
            
            if (num1 < num2) return -1;
            else if (num1 > num2) return 1;
        }
        // Both versions are equal
        return 0;
    }
    
private:
    vector<int> splitVersion(string version) {
        vector<int> revisions;
        istringstream iss(version);
        string revision;
        while (getline(iss, revision, '.')) {
            revisions.push_back(stoi(revision));
        }
        return revisions;
    }
};