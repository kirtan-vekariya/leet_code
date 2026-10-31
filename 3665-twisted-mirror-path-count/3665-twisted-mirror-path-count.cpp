class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long MOD = 1e9 + 7;
        vector<vector<vector<pair<int, int>>>> dest(m + 1, vector<vector<pair<int, int>>>(n + 1, vector<pair<int, int>>(2, {-1, -1})));
        for(int r = m - 1 ; r >= 0 ; r--){
            for(int c = n - 1 ; c >= 0 ; c--){
                if(grid[r][c] == 0){
                    dest[r][c][0] = {r, c};
                    dest[r][c][1] = {r, c};
                }
                else{
                    dest[r][c][0] = dest[r + 1][c][1];
                    dest[r][c][1] = dest[r][c + 1][0];
                }
            }
        }
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[0][0] = 1;
        for(int r = 0 ; r < m ; r++){
            for(int c = 0 ; c < n ; c++){
                if(dp[r][c] == 0)continue;
                if(c + 1 < n){
                    auto [nr, nc] = dest[r][c + 1][0];
                    if(nr != -1)dp[nr][nc] = (dp[nr][nc] + dp[r][c]) % MOD;
                }
                if(r + 1 < m){
                    auto [nr, nc] = dest[r + 1][c][1];
                    if(nr != -1)dp[nr][nc] = (dp[nr][nc] + dp[r][c]) % MOD;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};