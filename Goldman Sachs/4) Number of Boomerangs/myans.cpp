class Solution {
public:
    int findD(vector<int>&a, vector<int>&b){
        return ((a[0]-b[0])*(a[0]-b[0])) + ((a[1]-b[1])*(a[1]-b[1]));
    }
    int numberOfBoomerangs(vector<vector<int>>& p) {
        int n = p.size(), ans = 0;
        for(int i=0; i<n; i++){
            unordered_map<int,int>mp;
            for(int j=0; j<n; j++){
                if(i == j) continue;
                mp[findD(p[i], p[j])]++;
            }
            for(auto &dis : mp){
                ans += dis.second*(dis.second-1);
            }
        }
        return ans;
    }
};
