class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        const int X = 1024;

        vector<vector<bool>> dp(n, vector<bool>(X, false));

        for (int i = 0; i < m; i++) {
            vector<bool> left(X, false);

            for (int j = 0; j < n; j++) {
                vector<bool> cur(X, false);

                if (i == 0 && j == 0) {
                    cur[grid[i][j]] = true;
                } else {
                    if (i > 0) {
                        for (int x = 0; x < X; x++) {
                            if (dp[j][x]) {
                                cur[x ^ grid[i][j]] = true;
                            }
                        }
                    }
                    if (j > 0) {
                        for (int x = 0; x < X; x++) {
                            if (left[x]) {
                                cur[x ^ grid[i][j]] = true;
                            }
                        }
                    }
                }

                dp[j] = cur;
                left = cur;
            }
        }

        for (int x = 0; x < X; x++) {
            if (dp[n - 1][x]) {
                return x;
            }
        }

        return -1;
    }
};