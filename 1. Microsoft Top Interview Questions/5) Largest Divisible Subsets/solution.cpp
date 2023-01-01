class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), maxi = 0, lastIdx = 0;
        sort(begin(nums), end(nums));
        vector<int>dp(n, 0), hash(n, 0);

        for(int i=0; i<n; i++){
            hash[i] = i;
            for(int j=0; j<i; j++){
                if(nums[i] % nums[j] == 0 && dp[i] < 1 + dp[j]){
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
            if(maxi < dp[i]){
                maxi = dp[i];
                lastIdx = i;
            }
        }
        vector<int>ans;
        ans.push_back(nums[lastIdx]);
        while(hash[lastIdx] != lastIdx){
            lastIdx = hash[lastIdx];
            ans.push_back(nums[lastIdx]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
