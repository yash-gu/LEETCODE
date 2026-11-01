class Solution {
public:
    string addBinary(string a, string b) {
        
        int al=a.size();
        int bl=b.size();
        int i=al-1;
        int j=bl-1;
        int carry=0;
        string ans="";
        while(i>=0||carry!=0||j>=0){
            int sum=0;
            if(i>=0){
                sum+=a[i]-'0';
                i--;
            }
            if(j>=0){
                sum+=b[j]-'0';
                j--;
            }
            sum+=carry;
            carry = sum / 2;
            ans += to_string(sum % 2);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};