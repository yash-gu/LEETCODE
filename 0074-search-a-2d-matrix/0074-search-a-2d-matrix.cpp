class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();

        //sort the row first 
        int left=0;
        int right=m-1;
        int i;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(matrix[mid][0]==target)return true;
            else if(matrix[mid][0]>target){
                right=mid-1;
            }else{
                i=mid;
                left=mid+1;
            }

        }
        
        left=0;
        right=n-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(matrix[i][mid]==target)return true;
            else if(matrix[i][mid]>target){
                right=mid-1;
            }else{
                left=mid+1;
            }

        }

        return false;

    }
};