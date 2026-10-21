class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> a;
        int maxlength = 0;
        int left = 0; 
        for(int  i = 0 ; i < s.length() ; i++){
            char curr = s[i];
            if(a.count(curr) && a[curr] >= left)left = a[curr] + 1;
            a[curr] = i;
            maxlength = max(maxlength,i - left + 1);
        }
        return maxlength;
    }
};