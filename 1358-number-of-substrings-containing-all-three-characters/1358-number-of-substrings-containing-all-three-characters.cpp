class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0;
        int cnt = 0;
        int n = s.length();
        vector<int> freq(3, 0);
        for(int i = 0 ; i < n ; i++){
            freq[s[i] - 'a']++;
            while(freq[0] > 0 && freq[1] > 0 && freq[2] > 0){
                cnt += n - i;
                freq[s[left] - 'a']--;
                left++;
            }
        }
        return cnt;
    }
};