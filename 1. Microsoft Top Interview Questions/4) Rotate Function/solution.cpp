class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0, ans = 0, n = nums.size();
        vector<int>dp(n, 0);
        for(int i=0; i<n; i++){
            sum += nums[i];
            dp[0] += i*nums[i];
        }
        ans = dp[0];
        for(int i=1; i<n; i++){
            dp[i] = dp[i-1] + (sum - (n*nums[n-i]));
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
