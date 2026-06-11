class Solution {
    const int MOD = 1e9 + 7;
private:
    int power(long long a, long long b){
        long long ans = 1;
        a%= MOD;
        while(b>0){
            if(b&1) ans = (ans * a)%MOD;
            a = (a*a)%MOD;
            b >>= 1;
        }
        return (int)ans;
    }
    int dfs(int node, int prev, vector<vector<int>>& adj){
        if(adj[node].size() == 0) return 0;
        int ans = 0;
        for(auto it : adj[node]){
            if(it != prev) ans = max(ans, 1 + dfs(it,node,adj));
        }
        return ans;
    }
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n+2);
        for(auto it : edges){
            adj[it[1]].push_back(it[0]);
            adj[it[0]].push_back(it[1]);

        }
        int depth = dfs(1,-1,adj);
        return power(2,depth-1);
    }
};