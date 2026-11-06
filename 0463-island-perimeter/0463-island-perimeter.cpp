class Solution {
    void sett(vector<vector<int>>& p, int i, int j) {
        if (i + 1 < p.size()) {
            p[i + 1][j] -= 2; 
        }
        if (j + 1 < p[0].size()) { 
            p[i][j + 1] -= 2; 
        }
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();

        vector<vector<int>> p(row,vector<int> (col,4));

        int perimeter=0;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    perimeter+=p[i][j];
                    sett(p,i,j);
                }
            }
        }
        return perimeter;
    }
};