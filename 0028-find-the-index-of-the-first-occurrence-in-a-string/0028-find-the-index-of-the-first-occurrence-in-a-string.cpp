class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=needle.size();
        int m=haystack.size();

        int i=0;
        int j=0;

        int ind=0;

        while(i<m && j<n){
            if(haystack[i]==needle[j]){
                if(j==0){
                    ind=i;
                }
                j++;
                i++;
                
            }else {
                if (j > 0) {
                    i = ind + 1; 
                    j = 0; 
                } else {
                    i++; 
                }
            }
        }
        if(j==n)return ind;
        return -1;
    }
};