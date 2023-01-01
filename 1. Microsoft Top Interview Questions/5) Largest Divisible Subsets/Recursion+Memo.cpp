class Solution {
    unordered_map<int, vector<int>>dp;
public:
    vector<int> solve(vector<int>&nums, int start){
        if(start >= size(nums))return {};

        if(dp.count(start)) return dp[start];

        vector<int>temp;
        for(int i=start+1; i<nums.size(); i++){
            if(nums[i] % nums[start]) continue;
            auto arr = solve(nums, i);
            if(arr.size() > dp[start].size()) dp[start] = arr;
        }
        dp[start].push_back(nums[start]);
        return dp[start];
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int>ans;
        for(int i=0; i<n; i++){
            auto temp = solve(nums, i);
            if(temp.size() > ans.size()) ans = temp;
        }
        return ans;
    }
};
