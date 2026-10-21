class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        if(is_sorted(s.begin(), s.end()))return 0;
        if(n == 2)return -1;
        char mid_min = 'z' + 1;
        char mid_max = 'a' - 1;
        for(int i = 1 ; i < n - 1 ; i++){
            mid_min = min(mid_min, s[i]);
            mid_max = max(mid_max, s[i]);
        }
        if(s[0] <= min(mid_min, s.back()) || s.back() >= max(s[0], mid_max))return 1;
        if(s.back() < mid_min && s[0] > mid_max)return 3;
        return 2;
    }
};