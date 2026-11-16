class Solution {
public:
    string digitSum(string s, int k) {
        while (s.length() > k) {
            string next_s = "";
            for (int i = 0; i < s.length(); i += k) {
                int group_sum = 0;
                
                for (int j = i; j < min((int)s.length(), i + k); ++j) {
                    group_sum += s[j] - '0';
                }
                next_s += to_string(group_sum);
            }
            
            s = next_s;
        }
        
        return s;
    }
};