class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        vector<pair<int, int>>dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] > 0){
                    long long island_sum = 0;
                    queue<pair<int, int>>q;
                    q.push({i, j});
                    island_sum = (island_sum + grid[i][j]) % k;
                    grid[i][j] = 0;
                    while(!q.empty()){
                        auto [r, c] = q.front();
                        q.pop();
                        for(auto& d : dirs){
                            int nr = r + d.first;
                            int nc = c + d.second;
                            if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > 0){
                                q.push({nr, nc});
                                island_sum = (island_sum + grid[nr][nc]) % k;
                                grid[nr][nc] = 0;
                            }
                        }
                    }
                    if(island_sum == 0)cnt++;
                }
            }
        }
        return cnt;
    }
};