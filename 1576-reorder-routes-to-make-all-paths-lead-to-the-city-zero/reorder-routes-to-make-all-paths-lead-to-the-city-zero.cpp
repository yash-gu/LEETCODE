class Solution {
public:
    void dfs(int node,vector<vector<int>>& connections,vector<vector<int>>& forward,vector<vector<int>>& backward,vector<int>& visited,int& ans){
        visited[node]=1;
        for(int i=0;i<forward[node].size();i++){
            if(!visited[forward[node][i]]){
                ans++;
                dfs(forward[node][i],connections,forward,backward,visited,ans);
            }
            
        }
        for(int i=0;i<backward[node].size();i++){
            if(!visited[backward[node][i]]){
                dfs(backward[node][i],connections,forward,backward,visited,ans);
            }
            
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int>visited(n,0);
        vector<vector<int>>forward(n);
        vector<vector<int>>backward(n);
        for(auto& connection:connections){
            int a=connection[0];
            int b=connection[1];
            forward[a].push_back(b);
            backward[b].push_back(a);
        }
        int ans=0;
        dfs(0,connections,forward,backward,visited,ans);

        return ans;
    }
};