class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int n = s.size();
        int totalChars = 0;
        for (char c : s) {
            if (c != '-') {
                totalChars++;
            }
        }
        
        if (totalChars == 0) return "";
        
        int numDashes = (totalChars - 1) / k;
        int m = totalChars + numDashes;
        
        string ans(m, ' ');
        
        int i = n - 1;     
        int j = m - 1;       
        int l = 0;         
        
        while (i >= 0) {
            if (s[i] == '-') {
                i--; 
                continue;
            }
            
            if (l == k) {
                ans[j] = '-';
                j--;
                l = 0; 
            }
            
            ans[j] = toupper(s[i]);
            j--;
            i--;
            l++;
        }
        
        return ans;
    }
};