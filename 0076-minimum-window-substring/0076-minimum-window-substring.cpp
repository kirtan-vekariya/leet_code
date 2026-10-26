class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length())return "";
        vector<int> map(128, 0);
        for(char c : t){
            map[c]++;
        }
        int left = 0;
        int right = 0;
        int min_start = 0;
        int min_len = INT_MAX;
        int requried = t.length();
        while(right < s.length()){
            if(map[s[right]] > 0)requried--;
            map[s[right]]--;
            right++;
            while(requried == 0){
                if(right - left < min_len){
                    min_len = right - left;
                    min_start = left;
                }
                map[s[left]]++;
                if(map[s[left]] > 0)requried++;
                left++;
            }
        }
        return min_len == INT_MAX ? "" : s.substr(min_start, min_len);
    }
};