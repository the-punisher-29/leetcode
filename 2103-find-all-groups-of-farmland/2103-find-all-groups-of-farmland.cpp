class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> result;
        int m = land.size();
        int n = land[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (land[i][j] == 1) {
                    int row = i;
                    int col = j;
                    while (row < m && land[row][j] == 1) {
                        ++row;
                    }
                    while (col < n && land[i][col] == 1) {
                        ++col;
                    }
                    --row;
                    --col;
                    result.push_back({i, j, row, col});
                    markVisited(land, i, j, row, col);
                }
            }
        }
        
        return result;
    }
private:
    void markVisited(vector<vector<int>>& land, int r1, int c1, int r2, int c2) {
        for (int i = r1; i <= r2; ++i) {
            for (int j = c1; j <= c2; ++j) {
                land[i][j] = 0;
            }
        }
    }
};