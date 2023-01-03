// Topological Sort question it is, whenever we have to maintain a order in graph or tree think topo
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pr) {
        vector<int>in(n, 0), topo;
        vector<int>adj[n];
        queue<int>q;

        for(auto it : pr){
            adj[it[1]].push_back(it[0]);
        }

        for(int i=0; i<n; i++){
            for(auto j : adj[i]){
                in[j]++;
            }
        }

        for(int i=0; i<n; i++){
            if(in[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front(); q.pop();
            topo.push_back(node);
            for(auto i : adj[node]){
                in[i]--;
                if(in[i] == 0){
                    q.push(i);
                }
            }
        }
        return topo.size() == n;
    }   
};
