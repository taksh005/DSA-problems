class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto& road : roads){
            int u = road[0];
            int v = road[1];
            int dis = road[2];
            adj[u].push_back({v,dis});
            adj[v].push_back({u,dis});
        }
        vector<bool> vis(n+1,false);
        queue<int> q;
        q.push(1);
        vis[1] = true;
        int ans = INT_MAX;
        while(!q.empty()){
            int it = q.front();
            q.pop();

            for(auto& edge : adj[it]){
                int next = edge.first;
                int dist = edge.second;
                ans = min(ans, dist);
                if(!vis[next]) vis[next] = true, q.push(next);
            }
        }
        return ans;
    }
};