class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        int ans = 0, n = p.size();

        for(int i=0; i<n; i++){
            int same = 1;
            unordered_map<double, int>mp;
            for(int j=i+1; j<n; j++){
                if(p[i][0] == p[j][0] && p[i][1] == p[j][1]){
                    same++;
                } else if(p[i][0] == p[j][0]){
                    mp[INT_MAX]++;
                } else{
                    double slope = double(p[i][1]-p[j][1]) / double(p[i][0] - p[j][0]);
                    mp[slope]++;
                }
            }
            int maxi = 0;
            for(auto i : mp){
                maxi = max(maxi, i.second);
            }
            maxi += same;
            ans = max(ans, maxi);
        }
        return ans;
    }
};
