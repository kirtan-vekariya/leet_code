class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int left = 0;
        int max_len = 0;
        int max_freq = 0;
        unordered_map<char, int> count;
        for(int i = 0 ; i < n ; i++){
            count[s[i]]++;
            max_freq = max(max_freq, count[s[i]]);
            if((i - left + 1) - max_freq > k){
                count[s[left]]--;
                left++;
            }
            max_len = max(max_len, i - left + 1);
        }
        return max_len;
    }
};