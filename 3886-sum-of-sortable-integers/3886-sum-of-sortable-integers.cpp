class Solution {
public:
bool f(vector<int>& text, vector<int>& pattern){
    int m = pattern.size();
    int n = text.size();
    if(m == 0)return true;
    vector<int> lps(m, 0);
    int len = 0;
    for(int i = 1 ; i <m ;){
        if(pattern[i] == pattern[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len != 0)len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    int i = 0;
    int j = 0;
    while(i < n){
        if(pattern[j] == text[i]){
            j++;
            i++;
        }
        if(j == m)return true;
        else if(i < n && pattern[j] != text[i]){
            if(j != 0)j = lps[j - 1];
            else i++;
        }
    }
    return false;
}
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sortednums = nums;
        sort(sortednums.begin(),sortednums.end());
        int totalsum = 0;
        for(int k = 1 ; k <= n ; k++){
            if(n % k != 0)continue;
            bool possible = true;
            for(int i = 0 ; i < n ; i+=k){
                vector<int> originalblock(nums.begin() + i, nums.begin() + i + k);
                vector<int> targetblock(sortednums.begin() + i, sortednums.begin() + i + k);
                vector<int> doubledblock = originalblock;
                doubledblock.insert(doubledblock.end(), originalblock.begin(), originalblock.end());
                if(!f(doubledblock, targetblock)){
                    possible = false;
                    break;
                }
            }
            if(possible)totalsum += k;
        }
        return totalsum;
    }
};