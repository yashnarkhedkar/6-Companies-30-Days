class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size(), ans =  INT_MAX;
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++){
            if(mp.count(cards[i])){
                ans = min(ans, i-mp[cards[i]]+1);
            }
            mp[cards[i]] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
