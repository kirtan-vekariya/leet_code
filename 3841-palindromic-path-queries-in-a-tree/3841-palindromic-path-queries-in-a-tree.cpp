class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) adj[e[0]].push_back(e[1]), adj[e[1]].push_back(e[0]);
        
        vector<int> in(n), out(n), d(n), val(n), bit(n + 2, 0);
        vector<vector<int>> up(n, vector<int>(16));
        int timer = 0;
        
        auto add = [&](int i, int v) { for(; i <= n; i += i & -i) bit[i] ^= v; };
        auto ask = [&](int i) { int r = 0; for(; i > 0; i -= i & -i) r ^= bit[i]; return r; };
        
        function<void(int, int)> dfs = [&](int u, int p) {
            in[u] = ++timer;
            up[u][0] = (p == -1 ? u : p);
            for (int i = 1; i < 16; ++i) up[u][i] = up[up[u][i - 1]][i - 1];
            
            for (int v : adj[u]) if (v != p) {
                d[v] = d[u] + 1;
                dfs(v, u);
            }
            out[u] = timer;
        };
        dfs(0, -1);
        
        auto get_lca = [&](int u, int v) {
            if (d[u] < d[v]) swap(u, v);
            for (int i = 15; i >= 0; --i) if (d[u] - (1 << i) >= d[v]) u = up[u][i];
            if (u == v) return u;
            for (int i = 15; i >= 0; --i) if (up[u][i] != up[v][i]) u = up[u][i], v = up[v][i];
            return up[u][0];
        };
        
        for (int i = 0; i < n; ++i) {
            val[i] = 1 << (s[i] - 'a');
            add(in[i], val[i]); 
            add(out[i] + 1, val[i]);
        }
        
        vector<bool> ans;
        for (auto& q : queries) {
            stringstream ss(q);
            string type; ss >> type;
            
            if (type == "update") {
                int u; char c; ss >> u >> c;
                int nv = 1 << (c - 'a'), diff = val[u] ^ nv;
                if (diff) {
                    add(in[u], diff); 
                    add(out[u] + 1, diff); 
                    val[u] = nv;
                }
            } else {
                int u, v; ss >> u >> v;
                int p_xor = ask(in[u]) ^ ask(in[v]) ^ val[get_lca(u, v)];
                ans.push_back((p_xor & (p_xor - 1)) == 0);
            }
        }
        return ans;
    }
};