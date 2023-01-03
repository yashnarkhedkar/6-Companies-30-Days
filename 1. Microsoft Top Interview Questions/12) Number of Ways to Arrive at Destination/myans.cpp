class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long, long long>>adj[n];
        int mod = 1e9+7;
        vector<long long>dist(n, LONG_MAX), ways(n, 0);

        for(auto road : roads){
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>>q;
        q.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;

        while(!q.empty()){
            auto top = q.top(); q.pop();
            long long node = top.second;
            long long dis = top.first;

            for(auto neigh : adj[node]){
                long long newNode = neigh.first;
                long long newDist = neigh.second;
                if(dis + newDist < dist[newNode]){
                    dist[newNode] = dis + newDist;
                    q.push({dist[newNode], newNode});
                    ways[newNode] = ways[node];
                } else if(dis + newDist == dist[newNode]){
                    ways[newNode] = (ways[newNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};
