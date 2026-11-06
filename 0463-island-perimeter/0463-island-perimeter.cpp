class Solution {
    void sett(vector<vector<int>>& p, int i, int j) {
        if (i - 1 >= 0) { 
            p[i - 1][j] -= 1; 
        }
        if (i + 1 < p.size()) {
            p[i + 1][j] -= 1; 
        }
        if (j - 1 >= 0) { 
            p[i][j - 1] -= 1; 
        }
        if (j + 1 < p[0].size()) { 
            p[i][j + 1] -= 1; 
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
                    sett(p,i,j);
                }
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    perimeter+=p[i][j];
                }
            }
        }
        return perimeter;
    }
};