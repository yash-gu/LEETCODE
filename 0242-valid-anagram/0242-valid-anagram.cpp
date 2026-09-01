class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> words;
        if (s.length() != t.length()) return false;
        for(char c:s){
            words[c]++;
        }
        for(char c:t){
            words[c]--;
        }
        for(auto word:words){
            if(word.second!=0)return false;
        }
        return true;

    }
};