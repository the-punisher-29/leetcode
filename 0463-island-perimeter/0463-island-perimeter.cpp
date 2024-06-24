class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int peri=0;
        int r=grid.size();
        int c=grid[0].size();
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                if(grid[i][j]==1){
                    peri=peri+4;
                    //up nd down
                    if(i>0 && grid[i-1][j]==1){
                        peri-=2;
                    }
                    //left nd right
                    if(j>0 && grid[i][j-1]==1){
                        peri-=2;
                    }
                }
            }
        }
        return peri;
    }
};