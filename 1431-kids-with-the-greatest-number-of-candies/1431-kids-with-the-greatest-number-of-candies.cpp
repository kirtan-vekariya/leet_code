class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> ans(n, true);
        int maxi=0;
        for(auto i : candies)maxi=max(maxi, i);
        for(int i = 0 ; i < n ; i++){
            int a = candies[i] + extraCandies;
            if(a<maxi)ans[i]=false;
        }
        return ans;
    }
};