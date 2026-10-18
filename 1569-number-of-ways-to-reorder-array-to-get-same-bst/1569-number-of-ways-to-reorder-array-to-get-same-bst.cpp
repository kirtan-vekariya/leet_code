class Solution {
public:
int MOD = 1e9 + 7;
vector<vector<int>> comb;
void precomputecomb(int n){
    comb.assign(n + 1, vector<int>(n + 1, 0));
    for(int i = 0 ; i <= n ; i++){
        comb[i][0] = 1;
        for(int  j =  1 ; j <= i ; j++){
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
        }
    }
}
long long dfs(vector<int>& nums){
    if(nums.size() <= 2)return 1;
    int root = nums[0];
    vector<int> left,right;
    for(int i = 1 ; i < nums.size() ; i++){
        if(nums[i] < root)left.push_back(nums[i]);
        else right.push_back(nums[i]);
    }
    long long waysleft = dfs(left);
    long long wayright = dfs(right);
    long long waysinterleave = comb[left.size() + right.size()][left.size()];
    long long totalways = (waysinterleave * waysleft) % MOD;
    totalways = (totalways * wayright) % MOD;
    return totalways;
}
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        precomputecomb(n);
        return (dfs(nums) - 1 + MOD) % MOD;
    }
};