class Solution {
public:
    string vectorToString(const vector<int>& vec, const string& delim = "") {
        ostringstream oss;
        for (size_t i = 0; i < vec.size(); ++i) {
            if (i > 0) oss << delim;
            oss << vec[i];
        }
        return oss.str();
    }
    
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int count = 0;
        vector<int> ans;
        
        while (i >= 0 || j >= 0 || count) {
            int bitA = (i >= 0) ? a[i--] - '0' : 0; 
            int bitB = (j >= 0) ? b[j--] - '0' : 0;
            
            int sum = bitA + bitB + count;
            ans.insert(ans.begin(), sum % 2);  
            count = sum / 2;                   
        }
        
        return vectorToString(ans, "");  
    }
};
