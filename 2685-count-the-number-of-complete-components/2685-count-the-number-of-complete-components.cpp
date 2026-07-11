class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<int> adj[n];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> vis(n,false);
        int ans = 0;
        for(int i = 0; i < n;i++){
            if(!vis[i]){
                queue<int> q;
                q.push(i);
                vis[i] = true;
                int vertice = 0, edge = 0;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    vertice++;
                    edge += adj[node].size();
                    for(int t : adj[node]){
                        if(!vis[t]){
                            q.push(t);
                            vis[t] = true;
                        }
                    }
                }
                edge /= 2;
                if(edge == ((vertice)*(vertice - 1) / 2)) ans++;
            }
         }
         return ans;
    }
};