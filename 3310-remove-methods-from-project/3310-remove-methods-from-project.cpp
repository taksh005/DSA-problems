class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        int m = invocations.size();
        vector<vector<int>> adj(n);
        for(auto it : invocations){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
        unordered_set<int> suspicious;
        suspicious.insert(k);
        vector<int> vis(n,0);
        queue<int> q;
        q.push(k);
        vis[k] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                if(vis[it] != 1){
                    q.push(it);
                    vis[it] = 1;
                    suspicious.insert(it);
                }
            }
        }
        bool canRemove = true;
        for(int i = 0; i < n; i++){
            if(suspicious.find(i) != suspicious.end()) continue;
            for(auto j : adj[i]){
                if(suspicious.find(j) != suspicious.end()){
                    canRemove = false;
                    break;
                } 
            }
            if(!canRemove) break;
        }
        vector<int> ans;
        if(canRemove){
            for(int i = 0; i < n; i++){
                if(suspicious.find(i) == suspicious.end()){
                    ans.push_back(i);
                }
            }
        }else{
            for(int i = 0; i < n; i++) ans.push_back(i);
        }
        return ans;
    }
};